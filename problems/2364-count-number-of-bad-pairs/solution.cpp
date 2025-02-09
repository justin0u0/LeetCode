/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-number-of-bad-pairs/
 * Runtime: 75ms (31.46%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long countBadPairs(const vector<int>& nums) {
    const int n = nums.size();

    long long pairs = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
      pairs += m[nums[i] - i];
      ++m[nums[i] - i];
    }
    return 1LL * n * (n - 1) / 2 - pairs;
  }
};
