/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minimumOperations(const vector<int>& nums) {
    int cnt[101] = {0};

    for (int i = nums.size() - 1; i >= 0; --i) {
      if (++cnt[nums[i]] > 1) {
        return i / 3 + 1;
      }
    }

    return 0;
  }
};
