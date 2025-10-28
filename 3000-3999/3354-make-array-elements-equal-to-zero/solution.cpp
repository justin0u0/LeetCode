/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/make-array-elements-equal-to-zero/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int countValidSelections(const vector<int>& nums) {
    const int total = accumulate(nums.begin(), nums.end(), 0);

    int sels = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];

      if (nums[i] == 0) {
        if (total == sum + sum) {
          sels += 2;
        } else if (abs(total - sum - sum) <= 1) {
          ++sels;
        }
      }
    }
    return sels;
  }
};
