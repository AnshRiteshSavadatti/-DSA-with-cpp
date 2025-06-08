import hashlib
from bitarray import bitarray

class BloomFilter:
    def __init__(self, size=1000, hash_count=3):
        self.size = size                  # Size of the bit array
        self.hash_count = hash_count      # Number of hash functions
        self.bit_array = bitarray(size)
        self.bit_array.setall(0)

    def _hashes(self, item):
        results = []
        for i in range(self.hash_count):
            hash_input = item + str(i)
            digest = hashlib.sha256(hash_input.encode('utf-8')).hexdigest()
            results.append(int(digest, 16) % self.size)
        return results

    def add(self, item):
        for index in self._hashes(item):
            self.bit_array[index] = 1

    def contains(self, item):
        return all(self.bit_array[index] for index in self._hashes(item))

if __name__ == '__main__':
    bf = BloomFilter(size=500, hash_count=4)

    bf.add("apple")
    bf.add("banana")

    print("apple:", bf.contains("apple"))    # True
    print("banana:", bf.contains("banana"))  # True
    print("cherry:", bf.contains("cherry"))  # Probably False
