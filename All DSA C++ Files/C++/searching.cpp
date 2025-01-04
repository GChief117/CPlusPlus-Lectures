// Linear Search
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int target = 30;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            cout << "Linear Search: Element found at index " << i << endl;
            return 0;
        }
    }
    cout << "Linear Search: Element not found" << endl;
    return 0;
}


// Binary Search
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int target = 40;
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            cout << "Binary Search: Element found at index " << mid << endl;
            return 0;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "Binary Search: Element not found" << endl;
    return 0;
}


// Depth-First Search (DFS)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    vector<vector<int>> graph = {
        {1, 2},    // Node 0
        {0, 3, 4}, // Node 1
        {0, 4},    // Node 2
        {1, 5},    // Node 3
        {1, 2, 5}, // Node 4
        {3, 4}     // Node 5
    };
    stack<int> s;
    vector<bool> visited(graph.size(), false);

    s.push(0);
    cout << "DFS Traversal: ";
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";
            for (auto neighbor : graph[node]) {
                if (!visited[neighbor]) s.push(neighbor);
            }
        }
    }
    cout << endl;
    return 0;
}


// Breadth-First Search (BFS)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    vector<vector<int>> graph = {
        {1, 2},    // Node 0
        {0, 3, 4}, // Node 1
        {0, 4},    // Node 2
        {1, 5},    // Node 3
        {1, 2, 5}, // Node 4
        {3, 4}     // Node 5
    };
    queue<int> q;
    vector<bool> visited(graph.size(), false);

    q.push(0);
    visited[0] = true;
    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (auto neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
    return 0;
}


// Jump Search
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70};
    int target = 40;
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            cout << "Jump Search: Element not found" << endl;
            return 0;
        }
    }

    while (arr[prev] < target) {
        prev++;
        if (prev == min(step, n)) {
            cout << "Jump Search: Element not found" << endl;
            return 0;
        }
    }

    if (arr[prev] == target)
        cout << "Jump Search: Element found at index " << prev << endl;
    else
        cout << "Jump Search: Element not found" << endl;

    return 0;
}


// Exponential Search
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70};
    int target = 50;

    if (arr[0] == target) {
        cout << "Exponential Search: Element found at index 0" << endl;
        return 0;
    }

    int i = 1;
    while (i < arr.size() && arr[i] <= target) i *= 2;

    int result = binarySearch(arr, i / 2, min(i, (int)arr.size() - 1), target);
    if (result != -1)
        cout << "Exponential Search: Element found at index " << result << endl;
    else
        cout << "Exponential Search: Element not found" << endl;

    return 0;
}


// Interpolation Search
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70};
    int target = 40;
    int low = 0, high = arr.size() - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) {
                cout << "Interpolation Search: Element found at index " << low << endl;
                return 0;
            }
            cout << "Interpolation Search: Element not found" << endl;
            return 0;
        }

        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == target) {
            cout << "Interpolation Search: Element found at index " << pos << endl;
            return 0;
        }
        if (arr[pos] < target) low = pos + 1;
        else high = pos - 1;
    }

    cout << "Interpolation Search: Element not found" << endl;
    return 0;
}


// Ternary Search
#include <iostream>
#include <vector>
using namespace std;

int ternarySearch(const vector<int>& arr, int left, int right, int target) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == target) return mid1;
        if (arr[mid2] == target) return mid2;

        if (target < arr[mid1]) return ternarySearch(arr, left, mid1 - 1, target);
        else if (target > arr[mid2]) return ternarySearch(arr, mid2 + 1, right, target);
        else return ternarySearch(arr, mid1 + 1, mid2 - 1, target);
    }
    return -1;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70};
    int target = 30;
    int result = ternarySearch(arr, 0, arr.size() - 1, target);
    if (result != -1)
        cout << "Ternary Search: Element found at index " << result << endl;
    else
        cout << "Ternary Search: Element not found" << endl;

    return 0;
}
