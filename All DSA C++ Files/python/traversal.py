# In-Order Traversal
class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def in_order_traversal(root):
    if root:
        in_order_traversal(root.left)
        print(root.data, end=" ")
        in_order_traversal(root.right)

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)

    print("In-Order Traversal:", end=" ")
    in_order_traversal(root)
    print()

# Pre-Order Traversal
class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def pre_order_traversal(root):
    if root:
        print(root.data, end=" ")
        pre_order_traversal(root.left)
        pre_order_traversal(root.right)

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)

    print("Pre-Order Traversal:", end=" ")
    pre_order_traversal(root)
    print()


# Post-Order Traversal
class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def post_order_traversal(root):
    if root:
        post_order_traversal(root.left)
        post_order_traversal(root.right)
        print(root.data, end=" ")

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)

    print("Post-Order Traversal:", end=" ")
    post_order_traversal(root)
    print()


# DFS Traversal
def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    print(start, end=" ")
    for neighbor in graph[start]:
        if neighbor not in visited:
            dfs(graph, neighbor, visited)

if __name__ == "__main__":
    graph = {
        0: [1, 2],
        1: [0, 3, 4],
        2: [0, 4],
        3: [1, 5],
        4: [1, 2, 5],
        5: [3, 4]
    }
    print("DFS Traversal:", end=" ")
    dfs(graph, 0)
    print()


# Level-Order Traversal
from collections import deque

class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def level_order_traversal(root):
    if not root:
        return
    queue = deque([root])
    while queue:
        node = queue.popleft()
        print(node.data, end=" ")
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)

    print("Level-Order Traversal:", end=" ")
    level_order_traversal(root)
    print()


# Backtracking Traversal: N-Queens Problem
def is_safe(board, row, col, n):
    for i in range(col):
        if board[row][i] == 1:
            return False
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    for i, j in zip(range(row, n), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    return True

def solve_n_queens(board, col, n):
    if col >= n:
        return True
    for i in range(n):
        if is_safe(board, i, col, n):
            board[i][col] = 1
            if solve_n_queens(board, col + 1, n):
                return True
            board[i][col] = 0
    return False

def print_board(board):
    for row in board:
        print(" ".join("Q" if cell == 1 else "." for cell in row))
    print()

if __name__ == "__main__":
    n = 8
    board = [[0 for _ in range(n)] for _ in range(n)]
    if solve_n_queens(board, 0, n):
        print("N-Queens Solution:")
        print_board(board)
    else:
        print("No solution exists")


# A* Search Algorithm
from heapq import heappop, heappush

def heuristic(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])  # Manhattan distance

def a_star_search(grid, start, goal):
    rows, cols = len(grid), len(grid[0])
    open_set = []
    heappush(open_set, (0 + heuristic(start, goal), 0, start))
    came_from = {}
    g_score = {start: 0}

    while open_set:
        _, current_cost, current = heappop(open_set)

        if current == goal:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            return path[::-1]

        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            neighbor = (current[0] + dx, current[1] + dy)
            if 0 <= neighbor[0] < rows and 0 <= neighbor[1] < cols and grid[neighbor[0]][neighbor[1]] == 1:
                tentative_g_score = current_cost + 1
                if tentative_g_score < g_score.get(neighbor, float('inf')):
                    g_score[neighbor] = tentative_g_score
                    heappush(open_set, (tentative_g_score + heuristic(neighbor, goal), tentative_g_score, neighbor))
                    came_from[neighbor] = current
    return None

if __name__ == "__main__":
    grid = [
        [1, 1, 1, 0],
        [1, 0, 1, 1],
        [1, 1, 1, 0],
        [0, 1, 1, 1]
    ]
    start = (0, 0)
    goal = (3, 3)

    path = a_star_search(grid, start, goal)
    if path:
        print("A* Path:", path)
    else:
        print("No path found")


# Dijkstra's Algorithm
from heapq import heappop, heappush

def dijkstra(graph, start):
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    priority_queue = [(0, start)]
    visited = set()

    while priority_queue:
        current_distance, current_node = heappop(priority_queue)

        if current_node in visited:
            continue
        visited.add(current_node)

        for neighbor, weight in graph[current_node]:
            distance = current_distance + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heappush(priority_queue, (distance, neighbor))

    return distances

if __name__ == "__main__":
    graph = {
        0: [(1, 4), (2, 1)],
        1: [(2, 2), (3, 5)],
        2: [(3, 8)],
        3: [(4, 6)],
        4: []
    }

    distances = dijkstra(graph, 0)
    print("Shortest distances from node 0:", distances)


# Prim's Algorithm
from heapq import heappop, heappush

def prims_algorithm(graph):
    mst = []
    visited = set()
    edges = [(0, 0, 0)]  # (weight, start, end)

    while edges:
        weight, start, end = heappop(edges)
        if end not in visited:
            visited.add(end)
            mst.append((start, end, weight))

            for neighbor, cost in graph[end]:
                if neighbor not in visited:
                    heappush(edges, (cost, end, neighbor))

    return mst

if __name__ == "__main__":
    graph = {
        0: [(1, 2), (3, 6)],
        1: [(0, 2), (2, 3), (3, 8)],
        2: [(1, 3), (3, 5)],
        3: [(0, 6), (1, 8), (2, 5)]
    }

    mst = prims_algorithm(graph)
    print("Prim's MST:", mst)


# Kruskal's Algorithm
def find(parent, node):
    if parent[node] != node:
        parent[node] = find(parent, parent[node])
    return parent[node]

def union(parent, rank, u, v):
    root_u = find(parent, u)
    root_v = find(parent, v)
    if root_u != root_v:
        if rank[root_u] > rank[root_v]:
            parent[root_v] = root_u
        elif rank[root_u] < rank[root_v]:
            parent[root_u] = root_v
        else:
            parent[root_v] = root_u
            rank[root_u] += 1

def kruskals_algorithm(edges, n):
    edges.sort(key=lambda x: x[2])
    parent = list(range(n))
    rank = [0] * n
    mst = []

    for u, v, weight in edges:
        if find(parent, u) != find(parent, v):
            mst.append((u, v, weight))
            union(parent, rank, u, v)

    return mst

if __name__ == "__main__":
    edges = [
        (0, 1, 10), (0, 2, 6), (0, 3, 5),
        (1, 3, 15), (2, 3, 4)
    ]
    n = 4
    mst = kruskals_algorithm(edges, n)
    print("Kruskal's MST:", mst)


# Eulerian Path/Circuit
from collections import defaultdict

def find_eulerian_path(graph, start):
    path = []
    stack = [start]

    while stack:
        u = stack[-1]
        if graph[u]:
            v = graph[u].pop()
            stack.append(v)
        else:
            path.append(stack.pop())

    return path[::-1]

if __name__ == "__main__":
    graph = defaultdict(list, {
        0: [1, 2],
        1: [0, 2],
        2: [0, 1, 3],
        3: [2]
    })
    path = find_eulerian_path(graph, 0)
    print("Eulerian Path:", path)


# Hamiltonian Path
def is_hamiltonian_path(graph, path):
    n = len(graph)
    if len(path) != n:
        return False
    visited = set()
    for i in range(n):
        if path[i] in visited or (i > 0 and path[i] not in graph[path[i - 1]]):
            return False
        visited.add(path[i])
    return True

def hamiltonian_path_util(graph, path, visited):
    if len(path) == len(graph):  # Base case: All vertices are in the path
        return True

    for neighbor in graph[path[-1]]:
        if neighbor not in visited:
            visited.add(neighbor)
            path.append(neighbor)

            if hamiltonian_path_util(graph, path, visited):
                return True

            # Backtrack
            path.pop()
            visited.remove(neighbor)

    return False

def find_hamiltonian_path(graph):
    for start in graph:
        path = [start]
        visited = {start}

        if hamiltonian_path_util(graph, path, visited):
            return path

    return None

if __name__ == "__main__":
    graph = {
        0: [1, 2],
        1: [0, 2, 3],
        2: [0, 1, 3],
        3: [1, 2]
    }

    path = find_hamiltonian_path(graph)
    if path:
        print("Hamiltonian Path:", path)
    else:
        print("No Hamiltonian Path exists")


# Hamiltonian Circuit
def is_hamiltonian_circuit(graph, path):
    n = len(graph)
    if len(path) != n or path[0] not in graph[path[-1]]:
        return False
    visited = set()
    for i in range(n):
        if path[i] in visited or (i > 0 and path[i] not in graph[path[i - 1]]):
            return False
        visited.add(path[i])
    return True

def hamiltonian_circuit_util(graph, path, visited):
    if len(path) == len(graph):
        return path[0] in graph[path[-1]]  # Check if circuit exists

    for neighbor in graph[path[-1]]:
        if neighbor not in visited:
            visited.add(neighbor)
            path.append(neighbor)

            if hamiltonian_circuit_util(graph, path, visited):
                return True

            # Backtrack
            path.pop()
            visited.remove(neighbor)

    return False

def find_hamiltonian_circuit(graph):
    for start in graph:
        path = [start]
        visited = {start}

        if hamiltonian_circuit_util(graph, path, visited):
            path.append(path[0])  # Close the circuit
            return path

    return None

if __name__ == "__main__":
    graph = {
        0: [1, 2],
        1: [0, 2, 3],
        2: [0, 1, 3],
        3: [1, 2]
    }

    circuit = find_hamiltonian_circuit(graph)
    if circuit:
        print("Hamiltonian Circuit:", circuit)
    else:
        print("No Hamiltonian Circuit exists")
