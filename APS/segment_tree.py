class SegmentTree:
    def __init__(self, arr):
        self.n = len(arr)
        self.tree = [0] * (4 * self.n)  # Large enough space
        self._build(arr, 0, 0, self.n - 1)

    def _build(self, arr, node, start, end):
        if start == end:
            self.tree[node] = arr[start]
        else:
            mid = (start + end) // 2
            self._build(arr, 2*node + 1, start, mid)
            self._build(arr, 2*node + 2, mid + 1, end)
            self.tree[node] = self.tree[2*node + 1] + self.tree[2*node + 2]

    def update(self, index, value):
        self._update(0, 0, self.n - 1, index, value)

    def _update(self, node, start, end, index, value):
        if start == end:
            self.tree[node] = value
        else:
            mid = (start + end) // 2
            if index <= mid:
                self._update(2*node + 1, start, mid, index, value)
            else:
                self._update(2*node + 2, mid + 1, end, index, value)
            self.tree[node] = self.tree[2*node + 1] + self.tree[2*node + 2]

    def query(self, l, r):
        return self._query(0, 0, self.n - 1, l, r)

    def _query(self, node, start, end, l, r):
        if r < start or end < l:
            return 0  # No overlap
        if l <= start and end <= r:
            return self.tree[node]  # Total overlap
        mid = (start + end) // 2
        left_sum = self._query(2*node + 1, start, mid, l, r)
        right_sum = self._query(2*node + 2, mid + 1, end, l, r)
        return left_sum + right_sum

if __name__ == '__main__':
    arr = [1, 3, 5, 7, 9, 11]
    st = SegmentTree(arr)

    print("Sum [1, 3]:", st.query(1, 3))  # 3 + 5 + 7 = 15
    st.update(1, 10)                      # arr[1] = 10
    print("After update: Sum [1, 3]:", st.query(1, 3))  # 10 + 5 + 7 = 22
