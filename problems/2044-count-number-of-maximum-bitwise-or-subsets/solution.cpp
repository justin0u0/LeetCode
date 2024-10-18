/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
 * Runtime: 75ms (26.34%)
 */

class Solution {
public:
  int countMaxOrSubsets(const vector<int>& nums) {
    int all = 0;
    for (int num : nums) {
      all |= num;
    }

    const int n = nums.size();
    int answer = 0;
    for (int i = 0; i < (1 << n); ++i) {
      int res = 0;
      for (int j = 0; j < n; ++j) {
        if (i & (1 << j)) {
          res |= nums[j];
        }
      }
      if (res == all) {
        ++answer;
      }
    }
    return answer;
  }
};
