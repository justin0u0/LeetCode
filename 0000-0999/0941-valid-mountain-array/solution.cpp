/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/valid-mountain-array/
 * Runtime: 46ms
 */

class Solution {
public:
  bool validMountainArray(vector<int>& arr) {
    int n = (int)arr.size();

    if (n < 3) {
      return false;
    }

    int l = 0, r = n - 1;
    while (l < n - 1 && arr[l] < arr[l + 1]) {
      ++l;
    }
    while (r > 1 && arr[r - 1] > arr[r]) {
      --r;
    }

    return l == r && (l != 0) && (r != n - 1);
  }
};
