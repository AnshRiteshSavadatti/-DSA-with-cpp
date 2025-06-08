import os
import json
from sortedcontainers import SortedDict

class LSMTree:
    def __init__(self, dir_path='lsm_data', memtable_threshold=5):
        self.memtable = SortedDict()
        self.memtable_threshold = memtable_threshold
        self.dir_path = dir_path
        self.wal_path = os.path.join(dir_path, 'wal.log')

        os.makedirs(dir_path, exist_ok=True)
        self._load_wal()

    def _load_wal(self):
        if os.path.exists(self.wal_path):
            with open(self.wal_path, 'r') as wal:
                for line in wal:
                    key, value = json.loads(line.strip())
                    self.memtable[key] = value

    def _flush_memtable_to_disk(self):
        if not self.memtable:
            return

        sstable_id = len([f for f in os.listdir(self.dir_path) if f.startswith("sstable_")])
        sstable_path = os.path.join(self.dir_path, f"sstable_{sstable_id}.json")
        with open(sstable_path, 'w') as f:
            json.dump(self.memtable, f)

        self.memtable.clear()
        open(self.wal_path, 'w').close()  # clear WAL

    def put(self, key, value):
        with open(self.wal_path, 'a') as wal:
            wal.write(json.dumps((key, value)) + "\n")

        self.memtable[key] = value
        if len(self.memtable) >= self.memtable_threshold:
            self._flush_memtable_to_disk()

    def get(self, key):
        if key in self.memtable:
            return self.memtable[key]

        for filename in sorted(os.listdir(self.dir_path), reverse=True):
            if filename.startswith("sstable_"):
                with open(os.path.join(self.dir_path, filename), 'r') as f:
                    data = json.load(f)
                    if key in data:
                        return data[key]

        return None

    def compact(self):
        combined = SortedDict()

        for filename in sorted(os.listdir(self.dir_path)):
            if filename.startswith("sstable_"):
                with open(os.path.join(self.dir_path, filename), 'r') as f:
                    data = json.load(f)
                    combined.update(data)
                os.remove(os.path.join(self.dir_path, filename))

        sstable_path = os.path.join(self.dir_path, "sstable_0.json")
        with open(sstable_path, 'w') as f:
            json.dump(combined, f)

    def delete(self, key):
        self.put(key, None)



lsm = LSMTree()

lsm.put("a", "1")
lsm.put("b", "2")
lsm.put("c", "3")
lsm.put("d", "4")
lsm.put("e", "5")

print(lsm.get("b"))  # Output: "2"

lsm.put("f", "6")  # triggers flush
print(lsm.get("a"))  # Still accessible from SSTable

lsm.delete("b")
print(lsm.get("b"))  # Output: None

lsm.compact()  # Optional: Run compaction
