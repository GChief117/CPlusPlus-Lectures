// In-Order Traversal
class TreeNode {
    int data;
    TreeNode left, right;

    TreeNode(int data) {
        this.data = data;
        left = right = null;
    }
}

public class InOrderTraversal {
    public static void inOrder(TreeNode root) {
        if (root != null) {
            inOrder(root.left);
            System.out.print(root.data + " ");
            inOrder(root.right);
        }
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        System.out.print("In-Order Traversal: ");
        inOrder(root);
        System.out.println();
    }
}


// Pre-Order Traversal
class PreOrderTraversal {
    public static void preOrder(TreeNode root) {
        if (root != null) {
            System.out.print(root.data + " ");
            preOrder(root.left);
            preOrder(root.right);
        }
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        System.out.print("Pre-Order Traversal: ");
        preOrder(root);
        System.out.println();
    }
}

// Post-Order Traversal
class PostOrderTraversal {
    public static void postOrder(TreeNode root) {
        if (root != null) {
            postOrder(root.left);
            postOrder(root.right);
            System.out.print(root.data + " ");
        }
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        System.out.print("Post-Order Traversal: ");
        postOrder(root);
        System.out.println();
    }
}


// DFS Traversal
import java.util.*;

public class DFSTraversal {
    public static void dfs(Map<Integer, List<Integer>> graph, int start, Set<Integer> visited) {
        visited.add(start);
        System.out.print(start + " ");
        for (int neighbor : graph.getOrDefault(start, new ArrayList<>())) {
            if (!visited.contains(neighbor)) {
                dfs(graph, neighbor, visited);
            }
        }
    }

    public static void main(String[] args) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        graph.put(0, Arrays.asList(1, 2));
        graph.put(1, Arrays.asList(0, 3, 4));
        graph.put(2, Arrays.asList(0, 4));
        graph.put(3, Arrays.asList(1, 5));
        graph.put(4, Arrays.asList(1, 2, 5));
        graph.put(5, Arrays.asList(3, 4));

        System.out.print("DFS Traversal: ");
        dfs(graph, 0, new HashSet<>());
        System.out.println();
    }
}


// Level-Order Traversal
import java.util.*;

public class LevelOrderTraversal {
    public static void levelOrder(TreeNode root) {
        if (root == null) return;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            System.out.print(node.data + " ");

            if (node.left != null) queue.add(node.left);
            if (node.right != null) queue.add(node.right);
        }
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        System.out.print("Level-Order Traversal: ");
        levelOrder(root);
        System.out.println();
    }
}


// Backtracking Traversal: N-Queens Problem
import java.util.*;

public class NQueens {
    public static boolean isSafe(int[][] board, int row, int col, int n) {
        for (int i = 0; i < col; i++) if (board[row][i] == 1) return false;
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) if (board[i][j] == 1) return false;
        for (int i = row, j = col; i < n && j >= 0; i++, j--) if (board[i][j] == 1) return false;
        return true;
    }

    public static boolean solveNQueens(int[][] board, int col, int n) {
        if (col >= n) return true;

        for (int i = 0; i < n; i++) {
            if (isSafe(board, i, col, n)) {
                board[i][col] = 1;
                if (solveNQueens(board, col + 1, n)) return true;
                board[i][col] = 0; // Backtrack
            }
        }
        return false;
    }

    public static void printBoard(int[][] board, int n) {
        for (int[] row : board) {
            for (int cell : row) {
                System.out.print((cell == 1 ? "Q " : ". "));
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int n = 8;
        int[][] board = new int[n][n];
        if (solveNQueens(board, 0, n)) {
            System.out.println("N-Queens Solution:");
            printBoard(board, n);
        } else {
            System.out.println("No solution exists");
        }
    }
}



// A* Search Algorithm
import java.util.*;

public class AStarSearch {
    static class Node implements Comparable<Node> {
        int x, y, cost, heuristic;

        Node(int x, int y, int cost, int heuristic) {
            this.x = x;
            this.y = y;
            this.cost = cost;
            this.heuristic = heuristic;
        }

        @Override
        public int compareTo(Node other) {
            return (this.cost + this.heuristic) - (other.cost + other.heuristic);
        }
    }

    public static List<int[]> aStar(int[][] grid, int[] start, int[] goal) {
        PriorityQueue<Node> openSet = new PriorityQueue<>();
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        Map<int[], int[]> cameFrom = new HashMap<>();

        openSet.add(new Node(start[0], start[1], 0, heuristic(start, goal)));

        while (!openSet.isEmpty()) {
            Node current = openSet.poll();
            if (current.x == goal[0] && current.y == goal[1]) {
                return reconstructPath(cameFrom, start, goal);
            }

            if (visited[current.x][current.y]) continue;
            visited[current.x][current.y] = true;

            for (int[] direction : new int[][] {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
                int nx = current.x + direction[0], ny = current.y + direction[1];
                if (isValid(grid, nx, ny) && !visited[nx][ny]) {
                    int newCost = current.cost + 1;
                    openSet.add(new Node(nx, ny, newCost, heuristic(new int[] {nx, ny}, goal)));
                    cameFrom.put(new int[] {nx, ny}, new int[] {current.x, current.y});
                }
            }
        }

        return null;
    }

    private static List<int[]> reconstructPath(Map<int[], int[]> cameFrom, int[] start, int[] goal) {
        List<int[]> path = new ArrayList<>();
        int[] current = goal;
        while (!Arrays.equals(current, start)) {
            path.add(current);
            current = cameFrom.get(current);
        }
        path.add(start);
        Collections.reverse(path);
        return path;
    }

    private static int heuristic(int[] a, int[] b) {
        return Math.abs(a[0] - b[0]) + Math.abs(a[1] - b[1]);
    }

    private static boolean isValid(int[][] grid, int x, int y) {
        return x >= 0 && y >= 0 && x < grid.length && y < grid[0].length && grid[x][y] == 1;
    }

    public static void main(String[] args) {
        int[][] grid = {
            {1, 1, 1, 0},
            {1, 0, 1, 1},
            {1, 1, 1, 0},
            {0, 1, 1, 1}
        };
        int[] start = {0, 0};
        int[] goal = {3, 3};

        List<int[]> path = aStar(grid, start, goal);
        if (path != null) {
            System.out.println("A* Path:");
            for (int[] p : path) System.out.println(Arrays.toString(p));
        } else {
            System.out.println("No path found");
        }
    }
}


// Dijkstra's Algorithm
import java.util.*;

public class DijkstraAlgorithm {
    public static Map<Integer, Integer> dijkstra(Map<Integer, List<int[]>> graph, int start) {
        Map<Integer, Integer> distances = new HashMap<>();
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        pq.add(new int[] {start, 0});

        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int node = current[0], distance = current[1];

            if (distances.containsKey(node)) continue;
            distances.put(node, distance);

            for (int[] neighbor : graph.getOrDefault(node, new ArrayList<>())) {
                if (!distances.containsKey(neighbor[0])) {
                    pq.add(new int[] {neighbor[0], distance + neighbor[1]});
                }
            }
        }

        return distances;
    }

    public static void main(String[] args) {
        Map<Integer, List<int[]>> graph = new HashMap<>();
        graph.put(0, Arrays.asList(new int[] {1, 4}, new int[] {2, 1}));
        graph.put(1, Arrays.asList(new int[] {2, 2}, new int[] {3, 5}));
        graph.put(2, Arrays.asList(new int[] {3, 8}));
        graph.put(3, Arrays.asList(new int[] {4, 6}));
        graph.put(4, new ArrayList<>());

        Map<Integer, Integer> distances = dijkstra(graph, 0);
        System.out.println("Shortest distances from node 0: " + distances);
    }
}


// Prim's Algorithm
import java.util.*;

public class PrimsAlgorithm {
    public static List<int[]> primsAlgorithm(Map<Integer, List<int[]>> graph, int start) {
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        Set<Integer> visited = new HashSet<>();
        List<int[]> mst = new ArrayList<>();

        pq.add(new int[] {0, start, -1});

        while (!pq.isEmpty()) {
            int[] edge = pq.poll();
            int weight = edge[0], node = edge[1], parent = edge[2];

            if (visited.contains(node)) continue;
            visited.add(node);

            if (parent != -1) mst.add(new int[] {parent, node, weight});

            for (int[] neighbor : graph.getOrDefault(node, new ArrayList<>())) {
                if (!visited.contains(neighbor[0])) {
                    pq.add(new int[] {neighbor[1], neighbor[0], node});
                }
            }
        }

        return mst;
    }

    public static void main(String[] args) {
        Map<Integer, List<int[]>> graph = new HashMap<>();
        graph.put(0, Arrays.asList(new int[] {1, 2}, new int[] {3, 6}));
        graph.put(1, Arrays.asList(new int[] {0, 2}, new int[] {2, 3}, new int[] {3, 8}));
        graph.put(2, Arrays.asList(new int[] {1, 3}, new int[] {3, 5}));
        graph.put(3, Arrays.asList(new int[] {0, 6}, new int[] {1, 8}, new int[] {2, 5}));

        List<int[]> mst = primsAlgorithm(graph, 0);
        System.out.println("Prim's MST:");
        for (int[] edge : mst) {
            System.out.println(Arrays.toString(edge));
        }
    }
}


// Kruskal's Algorithm
import java.util.*;

public class KruskalsAlgorithm {
    static class Edge implements Comparable<Edge> {
        int src, dest, weight;

        Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge other) {
            return this.weight - other.weight;
        }
    }

    static class UnionFind {
        int[] parent, rank;

        UnionFind(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) parent[i] = i;
        }

        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }

        void union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        }
    }

    public static List<Edge> kruskalAlgorithm(List<Edge> edges, int n) {
        Collections.sort(edges);
        UnionFind uf = new UnionFind(n);
        List<Edge> mst = new ArrayList<>();

        for (Edge edge : edges) {
            if (uf.find(edge.src) != uf.find(edge.dest)) {
                mst.add(edge);
                uf.union(edge.src, edge.dest);
            }
        }

        return mst;
    }

    public static void main(String[] args) {
        List<Edge> edges = Arrays.asList(
            new Edge(0, 1, 10),
            new Edge(0, 2, 6),
            new Edge(0, 3, 5),
            new Edge(1, 3, 15),
            new Edge(2, 3, 4)
        );
        int n = 4;

        List<Edge> mst = kruskalAlgorithm(edges, n);
        System.out.println("Kruskal's MST:");
        for (Edge edge : mst) {
            System.out.println(edge.src + " - " + edge.dest + " : " + edge.weight);
        }
    }
}


// Eulerian Path/Circuit
import java.util.*;

public class EulerianPath {
    public static List<Integer> findEulerianPath(Map<Integer, List<Integer>> graph, int start) {
        Stack<Integer> stack = new Stack<>();
        List<Integer> path = new ArrayList<>();
        stack.push(start);

        while (!stack.isEmpty()) {
            int u = stack.peek();
            if (graph.get(u) != null && !graph.get(u).isEmpty()) {
                int v = graph.get(u).remove(0);
                stack.push(v);
            } else {
                path.add(stack.pop());
            }
        }

        Collections.reverse(path);
        return path;
    }

    public static void main(String[] args) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        graph.put(0, new ArrayList<>(Arrays.asList(1, 2)));
        graph.put(1, new ArrayList<>(Arrays.asList(0, 2)));
        graph.put(2, new ArrayList<>(Arrays.asList(0, 1, 3)));
        graph.put(3, new ArrayList<>(Arrays.asList(2)));

        List<Integer> path = findEulerianPath(graph, 0);
        System.out.println("Eulerian Path: " + path);
    }
}



// Hamiltonian Path/Circuit
import java.util.*;

public class HamiltonianPathCircuit {
    public static boolean isSafe(int vertex, boolean[] visited, List<Integer> path, Map<Integer, List<Integer>> graph) {
        return !visited[vertex] && (path.isEmpty() || graph.get(path.get(path.size() - 1)).contains(vertex));
    }

    public static boolean hamiltonianPathUtil(Map<Integer, List<Integer>> graph, boolean[] visited, List<Integer> path, int n) {
        if (path.size() == n) {
            return true;  // All vertices are in the path
        }

        for (int neighbor : graph.getOrDefault(path.get(path.size() - 1), new ArrayList<>())) {
            if (isSafe(neighbor, visited, path, graph)) {
                visited[neighbor] = true;
                path.add(neighbor);

                if (hamiltonianPathUtil(graph, visited, path, n)) return true;

                // Backtrack
                visited[neighbor] = false;
                path.remove(path.size() - 1);
            }
        }

        return false;
    }

    public static List<Integer> findHamiltonianPath(Map<Integer, List<Integer>> graph, int n) {
        for (int start : graph.keySet()) {
            List<Integer> path = new ArrayList<>();
            boolean[] visited = new boolean[n];
            path.add(start);
            visited[start] = true;

            if (hamiltonianPathUtil(graph, visited, path, n)) {
                return path;
            }
        }
        return null;
    }

    public static List<Integer> findHamiltonianCircuit(Map<Integer, List<Integer>> graph, int n) {
        List<Integer> path = findHamiltonianPath(graph, n);
        if (path != null && graph.get(path.get(path.size() - 1)).contains(path.get(0))) {
            path.add(path.get(0));  // Close the circuit
            return path;
        }
        return null;
    }

    public static void main(String[] args) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        graph.put(0, Arrays.asList(1, 2));
        graph.put(1, Arrays.asList(0, 2, 3));
        graph.put(2, Arrays.asList(0, 1, 3));
        graph.put(3, Arrays.asList(1, 2));

        List<Integer> path = findHamiltonianPath(graph, 4);
        if (path != null) {
            System.out.println("Hamiltonian Path: " + path);
        } else {
            System.out.println("No Hamiltonian Path exists");
        }

        List<Integer> circuit = findHamiltonianCircuit(graph, 4);
        if (circuit != null) {
            System.out.println("Hamiltonian Circuit: " + circuit);
        } else {
            System.out.println("No Hamiltonian Circuit exists");
        }
    }
}

