class HashMap:
    def __init__(self, size=100):
        self.size = size
        self.table = [[] for _ in range(size)]

    def _hash(self, key):
        return hash(key) % self.size

    def put(self, key, value):
        index = self._hash(key)
        # Check if key exists and update
        for i, (k, v) in enumerate(self.table[index]):
            if k == key:
                self.table[index][i] = (key, value)
                return
        # If key doesn't exist, append
        self.table[index].append((key, value))

    def get(self, key):
        index = self._hash(key)
        for (k, v) in self.table[index]:
            if k == key:
                return v
        return None  # Key not found

    def remove(self, key):
        index = self._hash(key)
        for i, (k, _) in enumerate(self.table[index]):
            if k == key:
                del self.table[index][i]
                return True
        return False  # Key not found

    def print_map(self):
        for i, bucket in enumerate(self.table):
            if bucket:
                print(f"{i}: {bucket}")

if __name__ == '__main__':
    hmap = HashMap(size=10)

    hmap.put("apple", 10)
    hmap.put("banana", 20)
    hmap.put("orange", 30)
    hmap.put("apple", 40)  # Update value

    print("Get apple:", hmap.get("apple"))     # 40
    print("Get banana:", hmap.get("banana"))   # 20
    print("Get grape:", hmap.get("grape"))     # None

    hmap.remove("banana")
    print("After removing banana:")
    hmap.print_map()
