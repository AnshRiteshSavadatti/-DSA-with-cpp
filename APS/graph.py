class Graph:
    def __init__(self, directed=False):
        self.adj_list = {}
        self.directed = directed

    def add_vertex(self, v):
        if v not in self.adj_list:
            self.adj_list[v] = []

    def add_edge(self, u, v):
        self.add_vertex(u)
        self.add_vertex(v)
        self.adj_list[u].append(v)
        if not self.directed:
            self.adj_list[v].append(u)

    def remove_edge(self, u, v):
        if u in self.adj_list and v in self.adj_list[u]:
            self.adj_list[u].remove(v)
        if not self.directed and v in self.adj_list and u in self.adj_list[v]:
            self.adj_list[v].remove(u)

    def remove_vertex(self, v):
        if v in self.adj_list:
            del self.adj_list[v]
        for key in self.adj_list:
            if v in self.adj_list[key]:
                self.adj_list[key].remove(v)

    def print_graph(self):
        for vertex in self.adj_list:
            print(f"{vertex} -> {self.adj_list[vertex]}")

if __name__ == '__main__':
    g = Graph(directed=False)

    g.add_edge('A', 'B')
    g.add_edge('A', 'C')
    g.add_edge('B', 'D')
    g.add_edge('C', 'D')
    g.add_edge('E', 'F')  # disconnected component

    print("Graph adjacency list:")
    g.print_graph()

    def dfs(self, start, visited=None):
        if visited is None:
            visited = set()
        visited.add(start)
        print(start, end=' ')
        for neighbor in self.adj_list.get(start, []):
            if neighbor not in visited:
                self.dfs(neighbor, visited)

    def bfs(self, start):
        visited = set()
        queue = [start]
        while queue:
            node = queue.pop(0)
            if node not in visited:
                print(node, end=' ')
                visited.add(node)
                queue.extend([n for n in self.adj_list[node] if n not in visited])
