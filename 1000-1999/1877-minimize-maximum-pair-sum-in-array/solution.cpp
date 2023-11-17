/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
 * Runtime: 145ms (98.34%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    const int n = nums.size();
    int answer = 0;
    for (int i = 0; i < n / 2; ++i) {
      answer = max(answer, nums[i] + nums[n - i - 1]);
    }
    return answer;
  }
};
