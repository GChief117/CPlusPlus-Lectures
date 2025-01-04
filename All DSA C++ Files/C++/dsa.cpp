// Arrays
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}


// Linked List
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* n) {
    while (n != nullptr) {
        cout << n->data << " ";
        n = n->next;
    }
}

int main() {
    Node* head = new Node{1, nullptr};
    Node* second = new Node{2, nullptr};
    Node* third = new Node{3, nullptr};

    head->next = second;
    second->next = third;

    cout << "Linked List: ";
    printList(head);
    cout << endl;

    return 0;
}


// Stacks
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Stack elements (top to bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}


// Queues
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Queue elements (front to back): ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}


// Hash Tables
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> hashTable;
    hashTable["one"] = 1;
    hashTable["two"] = 2;
    hashTable["three"] = 3;

    cout << "Hash Table elements: ";
    for (auto& pair : hashTable) {
        cout << pair.first << ":" << pair.second << " ";
    }
    cout << endl;

    return 0;
}


// Trees
#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    TreeNode* root = new TreeNode{1, nullptr, nullptr};
    root->left = new TreeNode{2, nullptr, nullptr};
    root->right = new TreeNode{3, nullptr, nullptr};

    cout << "Tree Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}


// Graphs
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    cout << "Graph Adjacency Matrix: " << endl;
    for (const auto& row : graph) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}


// Binary Search Tree
#include <iostream>
using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* insert(BSTNode* root, int value) {
    if (root == nullptr) return new BSTNode{value, nullptr, nullptr};
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

void inorderTraversal(BSTNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    BSTNode* root = nullptr;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);

    cout << "Binary Search Tree Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
