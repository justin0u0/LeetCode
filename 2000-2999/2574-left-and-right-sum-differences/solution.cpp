/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/left-and-right-sum-differences/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> leftRightDifference(const vector<int>& nums) {
    int sum = ranges::fold_left(nums.begin() + 1, nums.end(), 0, plus<>());

    vector<int> res(nums.size());
    res[0] = sum;
    for (int i = 1; i < nums.size(); ++i) {
      sum -= nums[i - 1] + nums[i];
      res[i] = abs(sum);
    }
    return res;
  }
};
