#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "O(1) Example: " << arr[2] << endl; // Accessing index 2
    return 0;
}


//Log
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 3, 5, 7, 9};
    int target = 7;
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            cout << "O(log n) Example: Found at index " << mid << endl;
            return 0;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "O(log n) Example: Not found" << endl;
    return 0;
}



//Linear
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    cout << "O(n) Example: Sum is " << sum << endl;
    return 0;
}


//Linearithmic--via merge sort
#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
using namespace std;

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    sort(arr.begin(), arr.end()); // Sorting the vector in ascending order
    cout << "O(n log n) Example: Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}


//Quadratic
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3};
    cout << "O(n^2) Example: All pairs: ";
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr.size(); ++j) {
            cout << "(" << arr[i] << ", " << arr[j] << ") ";
        }
    }
    cout << endl;
    return 0;
}


//Exponential
#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 5; // Calculate the 5th Fibonacci number
    cout << "O(2^n) Example: Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}


//Factorial
#include <iostream>
#include <string>
using namespace std;

void generatePermutations(string str, int left, int right) {
    if (left == right) {
        cout << str << " ";
        return;
    }
    for (int i = left; i <= right; ++i) {
        swap(str[left], str[i]);
        generatePermutations(str, left + 1, right);
        swap(str[left], str[i]); // Backtrack
    }
}

int main() {
    string str = "ABC";
    cout << "O(n!) Example: All permutations: ";
    generatePermutations(str, 0, str.size() - 1);
    cout << endl;
    return 0;
}

