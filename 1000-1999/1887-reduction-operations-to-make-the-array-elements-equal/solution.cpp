/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/
 * Runtime: 104ms (99.69%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int reductionOperations(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    const int n = nums.size();
    int answer = 0;
    for (int i = 1; i < n; ++i) {
      if (nums[i] != nums[i - 1]) {
        answer += i;
      }
    }
    return answer;
  }
};
