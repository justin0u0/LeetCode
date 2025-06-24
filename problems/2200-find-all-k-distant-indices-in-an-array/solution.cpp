/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> findKDistantIndices(vector<int>& nums, const int key, const int k) {
    const int n = nums.size();

    int j = n;
    for (int i = n - 1; i >= 0; --i) {
      if (nums[i] == key) {
        j = i - k;
      } else if (i >= j) {
        nums[i] = 0;
      }
    }

    j = -1;
    int l = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == key) {
        j = i + k;
        nums[l++] = i;
      } else if (nums[i] == 0 || i <= j) {
        nums[l++] = i;
      }
    }
    nums.resize(l);
    return nums;
  }
};
