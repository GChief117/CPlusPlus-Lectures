# Arrays
def array_example():
    arr = [1, 2, 3, 4, 5]
    print("Array elements:", arr)

if __name__ == "__main__":
    array_example()


# Linked List
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def print_list(head):
    current = head
    while current:
        print(current.data, end=" ")
        current = current.next
    print()

if __name__ == "__main__":
    head = Node(1)
    second = Node(2)
    third = Node(3)

    head.next = second
    second.next = third

    print("Linked List:")
    print_list(head)


# Stacks
def stack_example():
    stack = []
    stack.append(1)
    stack.append(2)
    stack.append(3)

    print("Stack elements (top to bottom):")
    while stack:
        print(stack.pop(), end=" ")
    print()

if __name__ == "__main__":
    stack_example()


# Queues
from collections import deque

def queue_example():
    queue = deque()
    queue.append(1)
    queue.append(2)
    queue.append(3)

    print("Queue elements (front to back):")
    while queue:
        print(queue.popleft(), end=" ")
    print()

if __name__ == "__main__":
    queue_example()


# Hash Tables
def hash_table_example():
    hash_table = {"one": 1, "two": 2, "three": 3}

    print("Hash Table elements:")
    for key, value in hash_table.items():
        print(f"{key}: {value}", end=" ")
    print()

if __name__ == "__main__":
    hash_table_example()


# Trees
class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def inorder_traversal(root):
    if root is None:
        return
    inorder_traversal(root.left)
    print(root.data, end=" ")
    inorder_traversal(root.right)

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)

    print("Tree Inorder Traversal:")
    inorder_traversal(root)
    print()


# Graphs
def graph_example():
    graph = {
        0: [1],
        1: [0, 2],
        2: [1]
    }

    print("Graph adjacency list:")
    for key, value in graph.items():
        print(f"{key}: {value}")

if __name__ == "__main__":
    graph_example()


# Binary Search Tree
class BSTNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insert(root, value):
    if root is None:
        return BSTNode(value)
    if value < root.data:
        root.left = insert(root.left, value)
    else:
        root.right = insert(root.right, value)
    return root

def inorder_traversal_bst(root):
    if root is None:
        return
    inorder_traversal_bst(root.left)
    print(root.data, end=" ")
    inorder_traversal_bst(root.right)

if __name__ == "__main__":
    root = None
    root = insert(root, 5)
    insert(root, 3)
    insert(root, 7)
    insert(root, 1)

    print("Binary Search Tree Inorder Traversal:")
    inorder_traversal_bst(root)
    print()
