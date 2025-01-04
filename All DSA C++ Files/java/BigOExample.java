// O(1) - Constant Time
import java.util.Arrays;

public class ConstantTimeExample {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        System.out.println("O(1) Example: " + arr[2]); // Accessing index 2
    }
}


// O(log n) - Logarithmic Time
import java.util.Arrays;

public class LogarithmicTimeExample {
    public static void main(String[] args) {
        int[] arr = {1, 3, 5, 7, 9};
        int target = 7;
        int left = 0, right = arr.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                System.out.println("O(log n) Example: Found at index " + mid);
                return;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        System.out.println("O(log n) Example: Not found");
    }
}


// O(n) - Linear Time
import java.util.Arrays;

public class LinearTimeExample {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        int sum = 0;

        for (int num : arr) {
            sum += num;
        }

        System.out.println("O(n) Example: Sum is " + sum);
    }
}


// O(n log n) - Linearithmic Time
import java.util.Arrays;

public class LinearithmicTimeExample {
    public static void main(String[] args) {
        int[] arr = {5, 2, 9, 1, 5, 6};
        Arrays.sort(arr); // Sorting in ascending order
        System.out.println("O(n log n) Example: Sorted array: " + Arrays.toString(arr));
    }
}


// O(n^2) - Quadratic Time
import java.util.Arrays;

public class QuadraticTimeExample {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3};
        System.out.println("O(n^2) Example: All pairs:");
        for (int i : arr) {
            for (int j : arr) {
                System.out.print("(" + i + ", " + j + ") ");
            }
        }
        System.out.println();
    }
}


// O(2^n) - Exponential Time
import java.util.Arrays;

public class ExponentialTimeExample {
    public static int fibonacci(int n) {
        if (n <= 1) return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    public static void main(String[] args) {
        int n = 5; // Calculate the 5th Fibonacci number
        System.out.println("O(2^n) Example: Fibonacci(" + n + ") = " + fibonacci(n));
    }
}


// O(n!) - Factorial Time
import java.util.Arrays;

public class FactorialTimeExample {
    public static void generatePermutations(char[] arr, int left, int right) {
        if (left == right) {
            System.out.print(String.valueOf(arr) + " ");
            return;
        }

        for (int i = left; i <= right; i++) {
            swap(arr, left, i);
            generatePermutations(arr, left + 1, right);
            swap(arr, left, i); // Backtrack
        }
    }

    public static void swap(char[] arr, int i, int j) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        String str = "ABC";
        char[] arr = str.toCharArray();
        System.out.println("O(n!) Example: All permutations:");
        generatePermutations(arr, 0, arr.length - 1);
        System.out.println();
    }
}
