// Linear Search
public class LinearSearch {
    public static int linearSearch(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) return i;
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {10, 20, 30, 40, 50};
        int target = 30;
        int result = linearSearch(arr, target);
        if (result != -1) {
            System.out.println("Linear Search: Element found at index " + result);
        } else {
            System.out.println("Linear Search: Element not found");
        }
    }
}


// Binary Search
public class BinarySearch {
    public static int binarySearch(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {10, 20, 30, 40, 50};
        int target = 40;
        int result = binarySearch(arr, target);
        if (result != -1) {
            System.out.println("Binary Search: Element found at index " + result);
        } else {
            System.out.println("Binary Search: Element not found");
        }
    }
}


// Depth-First Search (DFS)
import java.util.*;

public class DFS {
    public static void dfs(Map<Integer, List<Integer>> graph, int start) {
        Stack<Integer> stack = new Stack<>();
        Set<Integer> visited = new HashSet<>();
        stack.push(start);

        System.out.print("DFS Traversal: ");
        while (!stack.isEmpty()) {
            int node = stack.pop();
            if (!visited.contains(node)) {
                visited.add(node);
                System.out.print(node + " ");
                List<Integer> neighbors = graph.get(node);
                if (neighbors != null) {
                    for (int neighbor : neighbors) {
                        if (!visited.contains(neighbor)) {
                            stack.push(neighbor);
                        }
                    }
                }
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        graph.put(0, Arrays.asList(1, 2));
        graph.put(1, Arrays.asList(0, 3, 4));
        graph.put(2, Arrays.asList(0, 4));
        graph.put(3, Arrays.asList(1, 5));
        graph.put(4, Arrays.asList(1, 2, 5));
        graph.put(5, Arrays.asList(3, 4));

        dfs(graph, 0);
    }
}


// Breadth-First Search (BFS)
import java.util.*;

public class BFS {
    public static void bfs(Map<Integer, List<Integer>> graph, int start) {
        Queue<Integer> queue = new LinkedList<>();
        Set<Integer> visited = new HashSet<>();
        queue.add(start);
        visited.add(start);

        System.out.print("BFS Traversal: ");
        while (!queue.isEmpty()) {
            int node = queue.poll();
            System.out.print(node + " ");
            List<Integer> neighbors = graph.get(node);
            if (neighbors != null) {
                for (int neighbor : neighbors) {
                    if (!visited.contains(neighbor)) {
                        queue.add(neighbor);
                        visited.add(neighbor);
                    }
                }
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        graph.put(0, Arrays.asList(1, 2));
        graph.put(1, Arrays.asList(0, 3, 4));
        graph.put(2, Arrays.asList(0, 4));
        graph.put(3, Arrays.asList(1, 5));
        graph.put(4, Arrays.asList(1, 2, 5));
        graph.put(5, Arrays.asList(3, 4));

        bfs(graph, 0);
    }
}


// Jump Search
public class JumpSearch {
    public static int jumpSearch(int[] arr, int target) {
        int n = arr.length;
        int step = (int) Math.sqrt(n);
        int prev = 0;

        while (arr[Math.min(step, n) - 1] < target) {
            prev = step;
            step += (int) Math.sqrt(n);
            if (prev >= n) return -1;
        }

        for (int i = prev; i < Math.min(step, n); i++) {
            if (arr[i] == target) return i;
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {10, 20, 30, 40, 50, 60, 70};
        int target = 40;
        int result = jumpSearch(arr, target);
        if (result != -1) {
            System.out.println("Jump Search: Element found at index " + result);
        } else {
            System.out.println("Jump Search: Element not found");
        }
    }
}


// Exponential Search
public class ExponentialSearch {
    public static int binarySearch(int[] arr, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    public static int exponentialSearch(int[] arr, int target) {
        if (arr[0] == target) return 0;

        int i = 1;
        while (i < arr.length && arr[i] <= target) {
            i *= 2;
        }

        return binarySearch(arr, i / 2, Math.min(i, arr.length - 1), target);
    }

    public static void main(String[] args) {
        int[] arr = {10, 20, 30, 40, 50, 60, 70};
        int target = 50;
        int result = exponentialSearch(arr, target);
        if (result != -1) {
            System.out.println("Exponential Search: Element found at index " + result);
        } else {
            System.out.println("Exponential Search: Element not found");
        }
    }
}


// Interpolation Search
public class InterpolationSearch {
    public static int interpolationSearch(int[] arr, int target) {
        int low = 0, high = arr.length - 1;

        while (low <= high && target >= arr[low] && target <= arr[high]) {
            if (low == high) {
                if (arr[low] == target) return low;
                return -1;
            }

            int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

            if (arr[pos] == target) return pos;
            if (arr[pos] < target) low = pos + 1;
            else high = pos - 1;
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {10, 20, 30, 40, 50, 60, 70};
        int target = 40;
        int result = interpolationSearch(arr, target);
        if (result != -1) {
            System.out.println("Interpolation Search: Element found at index " + result);
        } else {
            System.out.println("Interpolation Search: Element not found");
        }
    }
}


// Ternary Search
public class TernarySearch {
    public static int ternarySearch(int[] arr, int left, int right, int target) {
        if (right >= left) {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;

            if (arr[mid1] == target) return mid1;
            if (arr[mid2] == target) return mid2;

            if (target < arr[mid1]) {
                return ternarySearch(arr, left, mid1 - 1, target);
            } else if (target > arr[mid2]) {
                return ternarySearch(arr, mid2 + 1, right, target);
            } else {
                return ternarySearch(arr, mid1 + 1, mid2 - 1, target);
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {10, 20, 30, 40, 50, 60, 70};
        int target = 30;
        int result = ternarySearch(arr, 0, arr.length - 1, target);
        if (result != -1) {
            System.out.println("Ternary Search: Element found at index " + result);
        } else {
            System.out.println("Ternary Search: Element not found");
        }
    }
}
