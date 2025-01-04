# Linear Search
def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1

if __name__ == "__main__":
    arr = [10, 20, 30, 40, 50]
    target = 30
    result = linear_search(arr, target)
    if result != -1:
        print(f"Linear Search: Element found at index {result}")
    else:
        print("Linear Search: Element not found")


# Binary Search
def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = left + (right - left) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

if __name__ == "__main__":
    arr = [10, 20, 30, 40, 50]
    target = 40
    result = binary_search(arr, target)
    if result != -1:
        print(f"Binary Search: Element found at index {result}")
    else:
        print("Binary Search: Element not found")


# Depth-First Search (DFS)
def dfs(graph, start):
    visited = set()
    stack = [start]

    print("DFS Traversal:", end=" ")
    while stack:
        node = stack.pop()
        if node not in visited:
            visited.add(node)
            print(node, end=" ")
            stack.extend(graph[node][::-1])  # Reverse to maintain order
    print()

if __name__ == "__main__":
    graph = {
        0: [1, 2],
        1: [0, 3, 4],
        2: [0, 4],
        3: [1, 5],
        4: [1, 2, 5],
        5: [3, 4]
    }
    dfs(graph, 0)


# Breadth-First Search (BFS)
from collections import deque

def bfs(graph, start):
    visited = set()
    queue = deque([start])

    print("BFS Traversal:", end=" ")
    while queue:
        node = queue.popleft()
        if node not in visited:
            visited.add(node)
            print(node, end=" ")
            queue.extend(graph[node])
    print()

if __name__ == "__main__":
    graph = {
        0: [1, 2],
        1: [0, 3, 4],
        2: [0, 4],
        3: [1, 5],
        4: [1, 2, 5],
        5: [3, 4]
    }
    bfs(graph, 0)


# Jump Search
import math

def jump_search(arr, target):
    n = len(arr)
    step = math.isqrt(n)
    prev = 0

    while arr[min(step, n) - 1] < target:
        prev = step
        step += math.isqrt(n)
        if prev >= n:
            return -1

    for i in range(prev, min(step, n)):
        if arr[i] == target:
            return i
    return -1

if __name__ == "__main__":
    arr = [10, 20, 30, 40, 50, 60, 70]
    target = 40
    result = jump_search(arr, target)
    if result != -1:
        print(f"Jump Search: Element found at index {result}")
    else:
        print("Jump Search: Element not found")


# Exponential Search
def binary_search(arr, left, right, target):
    while left <= right:
        mid = left + (right - left) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

def exponential_search(arr, target):
    if arr[0] == target:
        return 0

    i = 1
    while i < len(arr) and arr[i] <= target:
        i *= 2

    return binary_search(arr, i // 2, min(i, len(arr)) - 1, target)

if __name__ == "__main__":
    arr = [10, 20, 30, 40, 50, 60, 70]
    target = 50
    result = exponential_search(arr, target)
    if result != -1:
        print(f"Exponential Search: Element found at index {result}")
    else:
        print("Exponential Search: Element not found")


# Interpolation Search
def interpolation_search(arr, target):
    low, high = 0, len(arr) - 1

    while low <= high and target >= arr[low] and target <= arr[high]:
        if low == high:
            if arr[low] == target:
                return low
            return -1

        pos = low + ((target - arr[low]) * (high - low)) // (arr[high] - arr[low])

        if arr[pos] == target:
            return pos
        if arr[pos] < target:
            low = pos + 1
        else:
            high = pos - 1

    return -1

if __name__ == "__main__":
    arr = [10, 20, 30, 40, 50, 60, 70]
    target = 40
    result = interpolation_search(arr, target)
    if result != -1:
        print(f"Interpolation Search: Element found at index {result}")
    else:
        print("Interpolation Search: Element not found")


# Ternary Search
def ternary_search(arr, left, right, target):
    if right >= left:
        mid1 = left + (right - left) // 3
        mid2 = right - (right - left) // 3

        if arr[mid1] == target:
            return mid1
        if arr[mid2] == target:
            return mid2

        if target < arr[mid1]:
            return ternary_search(arr, left, mid1 - 1, target)
        elif target > arr[mid2]:
            return ternary_search(arr, mid2 + 1, right, target)
        else:
            return ternary_search(arr, mid1 + 1, mid2 - 1, target)
    return -1

if __name__ == "__main__":
    arr = [10, 20, 30, 40, 50, 60, 70]
    target = 30
    result = ternary_search(arr, 0, len(arr) - 1, target)
    if result != -1:
        print(f"Ternary Search: Element found at index {result}")
    else:
        print("Ternary Search: Element not found")
