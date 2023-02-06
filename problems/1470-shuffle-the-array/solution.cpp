/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/shuffle-the-array/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> answer;
    answer.reserve(n * 2);
    for (int i = 0; i < n; ++i) {
      answer.emplace_back(nums[i]);
      answer.emplace_back(nums[i + n]);
    }
    return answer;
  }
};
