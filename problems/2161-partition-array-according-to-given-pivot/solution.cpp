/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/partition-array-according-to-given-pivot/
 * Runtime: 2ms (90.85%)
 */

class Solution {
public:
  vector<int> pivotArray(const vector<int>& nums, const int pivot) {
    const int n = nums.size();
    vector<int> arr(n, pivot);

    int j = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] < pivot) {
        arr[j++] = nums[i];
      }
    }

    j = n - 1;
    for (int i = n - 1; i >= 0; --i) {
      if (nums[i] > pivot) {
        arr[j--] = nums[i];
      }
    }

    return arr;
  }
};
