/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-replacements-to-sort-the-array/
 * Runtime: 49ms (99.70%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long minimumReplacement(const vector<int>& nums) {
    int target = nums.back();
    long long answer = 0;
    for (int i = nums.size() - 1; i >= 0; --i) {
      int ops = (nums[i] - 1) / target;
      answer += ops;
      target = nums[i] / (ops + 1);
    }
    return answer;
  }
};
