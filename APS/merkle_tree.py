import hashlib

def sha256(data):
    return hashlib.sha256(data.encode('utf-8')).hexdigest()

class MerkleTree:
    def __init__(self, leaves):
        self.leaves = [sha256(leaf) for leaf in leaves]
        self.tree = []
        self.build_tree()

    def build_tree(self):
        current_level = self.leaves
        self.tree.append(current_level)
        
        while len(current_level) > 1:
            next_level = []
            for i in range(0, len(current_level), 2):
                left = current_level[i]
                right = current_level[i+1] if i+1 < len(current_level) else left
                combined_hash = sha256(left + right)
                next_level.append(combined_hash)
            self.tree.append(next_level)
            current_level = next_level

    def get_root(self):
        return self.tree[-1][0] if self.tree else None

    def get_proof(self, index):
        proof = []
        idx = index
        for level in self.tree[:-1]:
            sibling_idx = idx ^ 1  # toggle last bit to get sibling
            if sibling_idx < len(level):
                proof.append(level[sibling_idx])
            idx //= 2
        return proof

    @staticmethod
    def verify_proof(leaf, proof, root, index):
        computed_hash = sha256(leaf)
        idx = index
        for sibling in proof:
            if idx % 2 == 0:
                computed_hash = sha256(computed_hash + sibling)
            else:
                computed_hash = sha256(sibling + computed_hash)
            idx //= 2
        return computed_hash == root

if __name__ == '__main__':
    data = ['A', 'B', 'C', 'D']
    mtree = MerkleTree(data)

    root = mtree.get_root()
    print(f"Merkle Root: {root}")

    index = 2
    leaf = data[index]
    proof = mtree.get_proof(index)

    print(f"Proof for '{leaf}': {proof}")
    verified = MerkleTree.verify_proof(leaf, proof, root, index)
    print(f"Verification result: {verified}")
