# O(1) - Constant Time
def constant_time_example():
    arr = [1, 2, 3, 4, 5]
    print("O(1) Example:", arr[2])  # Accessing index 2

if __name__ == "__main__":
    constant_time_example()


# O(log n) - Logarithmic Time
def logarithmic_time_example():
    arr = [1, 3, 5, 7, 9]
    target = 7
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2
        if arr[mid] == target:
            print(f"O(log n) Example: Found at index {mid}")
            return
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    print("O(log n) Example: Not found")

if __name__ == "__main__":
    logarithmic_time_example()


# O(n) - Linear Time
def linear_time_example():
    arr = [1, 2, 3, 4, 5]
    total = sum(arr)
    print("O(n) Example: Sum is", total)

if __name__ == "__main__":
    linear_time_example()


# O(n log n) - Linearithmic Time
def linearithmic_time_example():
    arr = [5, 2, 9, 1, 5, 6]
    arr.sort()  # Sorting in ascending order
    print("O(n log n) Example: Sorted array:", arr)

if __name__ == "__main__":
    linearithmic_time_example()


# O(n^2) - Quadratic Time
def quadratic_time_example():
    arr = [1, 2, 3]
    print("O(n^2) Example: All pairs:")
    for i in arr:
        for j in arr:
            print(f"({i}, {j})", end=" ")
    print()

if __name__ == "__main__":
    quadratic_time_example()


# O(2^n) - Exponential Time
def fibonacci(n):
    if n <= 1:
        return n
    return fibonacci(n - 1) + fibonacci(n - 2)

def exponential_time_example():
    n = 5  # Calculate the 5th Fibonacci number
    print(f"O(2^n) Example: Fibonacci({n}) =", fibonacci(n))

if __name__ == "__main__":
    exponential_time_example()


# O(n!) - Factorial Time
def generate_permutations(string, left, right):
    if left == right:
        print("".join(string), end=" ")
        return
    for i in range(left, right + 1):
        string[left], string[i] = string[i], string[left]
        generate_permutations(string, left + 1, right)
        string[left], string[i] = string[i], string[left]  # Backtrack

def factorial_time_example():
    string = list("ABC")
    print("O(n!) Example: All permutations:")
    generate_permutations(string, 0, len(string) - 1)
    print()

if __name__ == "__main__":
    factorial_time_example()
