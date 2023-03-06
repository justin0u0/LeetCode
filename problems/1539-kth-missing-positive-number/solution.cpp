/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/kth-missing-positive-number/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int findKthPositive(vector<int>& arr, int k) {
    arr.emplace_back(INT_MAX);

    int l = 0;
    int r = arr.size();
    while (l < r) {
      int mid = (l + r) >> 1;
      if (arr[mid] - mid - 1 >= k) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    if (r == 0) {
      return k;
    }

    --r;
    int missings = arr[r] - r - 1;
    return arr[r] + k - missings;
  }
};
