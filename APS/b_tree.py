class BTreeNode:
    def __init__(self, t, leaf=False):
        self.t = t                  # Minimum degree (defines range for number of keys)
        self.leaf = leaf            # True when node is a leaf
        self.keys = []              # List of keys
        self.children = []          # List of child pointers

    def traverse(self):
        for i in range(len(self.keys)):
            if not self.leaf:
                self.children[i].traverse()
            print(self.keys[i], end=' ')
        if not self.leaf:
            self.children[-1].traverse()

    def search(self, k):
        i = 0
        while i < len(self.keys) and k > self.keys[i]:
            i += 1
        if i < len(self.keys) and self.keys[i] == k:
            return self
        if self.leaf:
            return None
        return self.children[i].search(k)

    def insert_non_full(self, k):
        i = len(self.keys) - 1
        if self.leaf:
            self.keys.append(None)
            while i >= 0 and k < self.keys[i]:
                self.keys[i+1] = self.keys[i]
                i -= 1
            self.keys[i+1] = k
        else:
            while i >= 0 and k < self.keys[i]:
                i -= 1
            i += 1
            if len(self.children[i].keys) == 2 * self.t - 1:
                self.split_child(i)
                if k > self.keys[i]:
                    i += 1
            self.children[i].insert_non_full(k)

    def split_child(self, i):
        t = self.t
        y = self.children[i]
        z = BTreeNode(t, y.leaf)
        self.children.insert(i + 1, z)
        self.keys.insert(i, y.keys[t-1])
        z.keys = y.keys[t:(2*t - 1)]
        y.keys = y.keys[0:(t-1)]

        if not y.leaf:
            z.children = y.children[t:2*t]
            y.children = y.children[0:t]


class BTree:
    def __init__(self, t):
        self.root = BTreeNode(t, True)
        self.t = t

    def traverse(self):
        if self.root:
            self.root.traverse()
            print()

    def search(self, k):
        return self.root.search(k) if self.root else None

    def insert(self, k):
        root = self.root
        if len(root.keys) == 2 * self.t - 1:
            s = BTreeNode(self.t, False)
            s.children.append(root)
            s.split_child(0)
            i = 0
            if s.keys[0] < k:
                i += 1
            s.children[i].insert_non_full(k)
            self.root = s
        else:
            root.insert_non_full(k)

if __name__ == '__main__':
    btree = BTree(t=2)  # t is the minimum degree

    for value in [10, 20, 5, 6, 12, 30, 7, 17]:
        btree.insert(value)

    print("Traversal of the tree:")
    btree.traverse()

    key = 6
    result = btree.search(key)
    print(f"Search for key {key}: {'Found' if result else 'Not found'}")
