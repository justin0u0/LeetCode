/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/
 * Runtime: 47ms (97.41%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minDifference(vector<int>& nums) {
    const int n = nums.size();
    if (n <= 4) {
      return 0;
    }
    sort(nums.begin(), nums.end());
    int answer = INT_MAX;
    for (int i = 0; i <= 3; ++i) {
      answer = min(answer, nums[n - 4 + i] - nums[i]);
    }
    return answer;
  }
};
