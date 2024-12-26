#include <iostream>
#include <vector>
using namespace std;

int binarySearchRecursive(const vector<int>& arr, int low, int high, int target) {
    if (low > high) return -1;

    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] > target) return binarySearchRecursive(arr, low, mid - 1, target);
    return binarySearchRecursive(arr, mid + 1, high, target);
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = binarySearchRecursive(arr, 0, n - 1, target);
    cout << result << endl;
    return 0;
}
