// In-Order Traversal
#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "In-Order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}

// Pre-Order Traversal
#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Pre-Order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    return 0;
}

// Post-Order Traversal
#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Post-Order Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}

// DFS Traversal
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(vector<vector<int>>& graph, int start) {
    vector<bool> visited(graph.size(), false);
    stack<int> s;
    s.push(start);

    cout << "DFS Traversal: ";
    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) s.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2}, {0, 3, 4}, {0, 4}, {1, 5}, {1, 2, 5}, {3, 4}
    };
    dfs(graph, 0);
    return 0;
}

// Level-Order Traversal
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);

    cout << "Level-Order Traversal: ";
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->data << " ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    levelOrderTraversal(root);

    return 0;
}

// Backtracking: N-Queens Problem
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j]) return false;
    }
    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int col, int n) {
    if (col >= n) return true;

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            if (solveNQueensUtil(board, col + 1, n)) return true;
            board[i][col] = 0; // Backtrack
        }
    }
    return false;
}

void solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (solveNQueensUtil(board, 0, n)) {
        cout << "N-Queens Solution:\n";
        for (const auto& row : board) {
            for (int cell : row) {
                cout << (cell ? "Q " : ". ");
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists for " << n << " queens.\n";
    }
}

int main() {
    int n = 8;
    solveNQueens(n);
    return 0;
}


// A* Search Algorithm
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
using namespace std;

struct Node {
    int x, y, cost, heuristic;
    Node(int x, int y, int cost, int heuristic) : x(x), y(y), cost(cost), heuristic(heuristic) {}
    bool operator<(const Node& other) const {
        return (cost + heuristic) > (other.cost + other.heuristic); // Min-heap
    }
};

int calculateHeuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2); // Manhattan distance
}

bool isValid(int x, int y, vector<vector<int>>& grid) {
    return x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1;
}

void aStarSearch(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) {
    priority_queue<Node> pq;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    pq.emplace(start.first, start.second, 0, calculateHeuristic(start.first, start.second, goal.first, goal.second));

    cout << "A* Path: ";
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (visited[current.x][current.y]) continue;
        visited[current.x][current.y] = true;
        cout << "(" << current.x << ", " << current.y << ") ";

        if (current.x == goal.first && current.y == goal.second) {
            cout << endl;
            return;
        }

        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (auto [dx, dy] : directions) {
            int nx = current.x + dx, ny = current.y + dy;
            if (isValid(nx, ny, grid) && !visited[nx][ny]) {
                int newCost = current.cost + 1;
                int heuristic = calculateHeuristic(nx, ny, goal.first, goal.second);
                pq.emplace(nx, ny, newCost, heuristic);
            }
        }
    }

    cout << "No path found" << endl;
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 1, 0},
        {0, 1, 1, 1}
    };
    pair<int, int> start = {0, 0};
    pair<int, int> goal = {3, 3};

    aStarSearch(grid, start, goal);
    return 0;
}

// Dijkstra's Algorithm
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& graph, int source) {
    vector<int> distance(graph.size(), INT_MAX);
    distance[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    cout << "Dijkstra's Shortest Path: ";
    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        cout << "(" << node << ", " << dist << ") ";

        for (auto neighbor : graph[node]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;
            if (distance[node] + weight < distance[nextNode]) {
                distance[nextNode] = distance[node] + weight;
                pq.push({distance[nextNode], nextNode});
            }
        }
    }
    cout << endl;
}

int main() {
    vector<vector<pair<int, int>>> graph = {
        {{1, 4}, {2, 1}}, // Node 0
        {{2, 2}, {3, 5}}, // Node 1
        {{3, 8}},         // Node 2
        {{4, 6}},         // Node 3
        {}                // Node 4
    };

    dijkstra(graph, 0);
    return 0;
}

// Prim's Algorithm
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

void primsAlgorithm(vector<vector<pair<int, int>>>& graph, int start) {
    int n = graph.size();
    vector<bool> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    int mstCost = 0;

    cout << "Prim's MST Edges:\n";
    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (inMST[node]) continue;
        inMST[node] = true;
        mstCost += weight;

        cout << "Node " << node << " with weight " << weight << endl;

        for (auto neighbor : graph[node]) {
            int nextNode = neighbor.first;
            int nextWeight = neighbor.second;
            if (!inMST[nextNode]) {
                pq.push({nextWeight, nextNode});
            }
        }
    }
    cout << "Total cost of MST: " << mstCost << endl;
}

int main() {
    vector<vector<pair<int, int>>> graph = {
        {{1, 2}, {3, 6}}, // Node 0
        {{0, 2}, {2, 3}, {3, 8}}, // Node 1
        {{1, 3}, {3, 5}}, // Node 2
        {{0, 6}, {1, 8}, {2, 5}}  // Node 3
    };

    primsAlgorithm(graph, 0);
    return 0;
}


// Kruskal's Algorithm
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int find(vector<int>& parent, int node) {
    if (parent[node] != node) {
        parent[node] = find(parent, parent[node]);
    }
    return parent[node];
}

void unionSets(vector<int>& parent, vector<int>& rank, int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

void kruskalsAlgorithm(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end());
    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    cout << "Kruskal's MST Edges:\n";
    int mstCost = 0;
    for (const auto& edge : edges) {
        if (find(parent, edge.src) != find(parent, edge.dest)) {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
            mstCost += edge.weight;
            unionSets(parent, rank, edge.src, edge.dest);
        }
    }
    cout << "Total cost of MST: " << mstCost << endl;
}

int main() {
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };
    int n = 4; // Number of nodes
    kruskalsAlgorithm(edges, n);
    return 0;
}


// Eulerian Path/Circuit
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void findEulerianPath(vector<vector<int>>& graph, int start) {
    stack<int> path, circuit;
    path.push(start);

    while (!path.empty()) {
        int u = path.top();
        if (!graph[u].empty()) {
            int v = graph[u].back();
            path.push(v);
            graph[u].pop_back();
        } else {
            circuit.push(u);
            path.pop();
        }
    }

    cout << "Eulerian Path/Circuit: ";
    while (!circuit.empty()) {
        cout << circuit.top() << " ";
        circuit.pop();
    }
    cout << endl;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2}, {0, 2}, {0, 1, 3}, {2}
    };
    findEulerianPath(graph, 0);
    return 0;
}


// Hamiltonian Path
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isHamiltonianPath(vector<vector<int>>& graph, vector<int>& path) {
    unordered_set<int> visited(path.begin(), path.end());
    if (visited.size() != graph.size()) return false;

    for (int i = 1; i < path.size(); i++) {
        int u = path[i - 1];
        int v = path[i];
        if (find(graph[u].begin(), graph[u].end(), v) == graph[u].end()) return false;
    }

    return true;
}

bool hamiltonianPathUtil(vector<vector<int>>& graph, vector<int>& path, unordered_set<int>& visited, int pos) {
    if (path.size() == graph.size()) return true;

    for (int neighbor : graph[pos]) {
        if (visited.find(neighbor) == visited.end()) {
            visited.insert(neighbor);
            path.push_back(neighbor);

            if (hamiltonianPathUtil(graph, path, visited, neighbor)) return true;

            // Backtrack
            path.pop_back();
            visited.erase(neighbor);
        }
    }

    return false;
}

vector<int> findHamiltonianPath(vector<vector<int>>& graph) {
    for (int start = 0; start < graph.size(); start++) {
        vector<int> path = {start};
        unordered_set<int> visited = {start};

        if (hamiltonianPathUtil(graph, path, visited, start)) return path;
    }

    return {};
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 3},
        {1, 2}
    };

    vector<int> path = findHamiltonianPath(graph);
    if (!path.empty()) {
        cout << "Hamiltonian Path: ";
        for (int node : path) cout << node << " ";
        cout << endl;
    } else {
        cout << "No Hamiltonian Path exists" << endl;
    }

    return 0;
}

// Hamiltonian Circuit
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isHamiltonianCircuit(vector<vector<int>>& graph, vector<int>& path) {
    unordered_set<int> visited(path.begin(), path.end());
    if (visited.size() != graph.size()) return false;

    for (int i = 1; i < path.size(); i++) {
        int u = path[i - 1];
        int v = path[i];
        if (find(graph[u].begin(), graph[u].end(), v) == graph[u].end()) return false;
    }

    // Check if the last vertex connects to the first
    return find(graph[path.back()].begin(), graph[path.back()].end(), path[0]) != graph[path.back()].end();
}

bool hamiltonianCircuitUtil(vector<vector<int>>& graph, vector<int>& path, unordered_set<int>& visited, int pos) {
    if (path.size() == graph.size()) {
        // Check if the last vertex connects back to the start
        return find(graph[path.back()].begin(), graph[path.back()].end(), path[0]) != graph[path.back()].end();
    }

    for (int neighbor : graph[pos]) {
        if (visited.find(neighbor) == visited.end()) {
            visited.insert(neighbor);
            path.push_back(neighbor);

            if (hamiltonianCircuitUtil(graph, path, visited, neighbor)) return true;

            // Backtrack
            path.pop_back();
            visited.erase(neighbor);
        }
    }

    return false;
}

vector<int> findHamiltonianCircuit(vector<vector<int>>& graph) {
    for (int start = 0; start < graph.size(); start++) {
        vector<int> path = {start};
        unordered_set<int> visited = {start};

        if (hamiltonianCircuitUtil(graph, path, visited, start)) {
            path.push_back(start);  // Close the circuit
            return path;
        }
    }

    return {};
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 3},
        {1, 2}
    };

    vector<int> circuit = findHamiltonianCircuit(graph);
    if (!circuit.empty()) {
        cout << "Hamiltonian Circuit: ";
        for (int node : circuit) cout << node << " ";
        cout << endl;
    } else {
        cout << "No Hamiltonian Circuit exists" << endl;
    }

    return 0;
}

