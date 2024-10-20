/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/peak-index-in-a-mountain-array/
 * Runtime: 83ms (99.59%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int l = 1;
    int r = (int)arr.size() - 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      cout << mid << endl;
      if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]) {
        l = mid + 1;
      } else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1]) {
        r = mid;
      } else {
        return mid;
      }
    }

    return -1;
  }
};

/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/peak-index-in-a-mountain-array/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int peakIndexInMountainArray(const vector<int>& arr) {
    int l = 1;
    int r = arr.size() - 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (arr[mid] > arr[mid + 1]) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return r;
  }
};
