/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sort-array-by-parity/
 * Runtime: 9ms
 */

class Solution {
public:
  vector<int> sortArrayByParity(vector<int>& nums) {
    int n = (int)nums.size();

    int j = 0;
    for (int i = 0; i < n; ++i) {
      if (!(nums[i] & 1)) {
        swap(nums[i], nums[j]);
        ++j;
      }
    }

    return nums;
  }
};
