// Arrays
import java.util.Arrays;

public class ArrayExample {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        System.out.println("Array elements: " + Arrays.toString(arr));
    }
}


// Linked List
class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class LinkedListExample {
    public static void printList(Node head) {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
    }

    public static void main(String[] args) {
        Node head = new Node(1);
        Node second = new Node(2);
        Node third = new Node(3);

        head.next = second;
        second.next = third;

        System.out.println("Linked List:");
        printList(head);
    }
}


// Stacks
import java.util.Stack;

public class StackExample {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        stack.push(1);
        stack.push(2);
        stack.push(3);

        System.out.println("Stack elements (top to bottom):");
        while (!stack.isEmpty()) {
            System.out.print(stack.pop() + " ");
        }
    }
}


// Queues
import java.util.LinkedList;
import java.util.Queue;

public class QueueExample {
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(1);
        queue.add(2);
        queue.add(3);

        System.out.println("Queue elements (front to back):");
        while (!queue.isEmpty()) {
            System.out.print(queue.poll() + " ");
        }
    }
}


// Hash Tables
import java.util.HashMap;

public class HashTableExample {
    public static void main(String[] args) {
        HashMap<String, Integer> hashTable = new HashMap<>();
        hashTable.put("one", 1);
        hashTable.put("two", 2);
        hashTable.put("three", 3);

        System.out.println("Hash Table elements:");
        for (String key : hashTable.keySet()) {
            System.out.print(key + ":" + hashTable.get(key) + " ");
        }
    }
}


// Trees
class TreeNode {
    int data;
    TreeNode left, right;

    TreeNode(int data) {
        this.data = data;
        left = right = null;
    }
}

public class TreeExample {
    public static void inorderTraversal(TreeNode root) {
        if (root == null) return;
        inorderTraversal(root.left);
        System.out.print(root.data + " ");
        inorderTraversal(root.right);
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);

        System.out.println("Tree Inorder Traversal:");
        inorderTraversal(root);
    }
}


// Graphs
import java.util.*;

public class GraphExample {
    public static void main(String[] args) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        graph.put(0, Arrays.asList(1));
        graph.put(1, Arrays.asList(0, 2));
        graph.put(2, Arrays.asList(1));

        System.out.println("Graph adjacency list:");
        for (int key : graph.keySet()) {
            System.out.println(key + ": " + graph.get(key));
        }
    }
}


// Binary Search Tree
class BSTNode {
    int data;
    BSTNode left, right;

    BSTNode(int data) {
        this.data = data;
        left = right = null;
    }
}

public class BinarySearchTreeExample {
    public static BSTNode insert(BSTNode root, int value) {
        if (root == null) return new BSTNode(value);
        if (value < root.data) {
            root.left = insert(root.left, value);
        } else {
            root.right = insert(root.right, value);
        }
        return root;
    }

    public static void inorderTraversal(BSTNode root) {
        if (root == null) return;
        inorderTraversal(root.left);
        System.out.print(root.data + " ");
        inorderTraversal(root.right);
    }

    public static void main(String[] args) {
        BSTNode root = null;
        root = insert(root, 5);
        insert(root, 3);
        insert(root, 7);
        insert(root, 1);

        System.out.println("Binary Search Tree Inorder Traversal:");
        inorderTraversal(root);
    }
}
