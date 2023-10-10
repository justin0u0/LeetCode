/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
 * Runtime: 95ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minOperations(vector<int>& nums) {
    const int n = nums.size();
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int l = 0;
    int r = 0;
    int answer = 0;
    const int m = nums.size();
    for (int i = 0; i < m; ++i) {
      while (l < i && nums[i] - nums[l] >= n) {
        ++l;
      }
      while (r < m && nums[r] - nums[i] < n) {
        ++r;
      }
      answer = max(answer, max(r - i, i - l));
    }
    return n - answer;
  }
};
