/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-good-pairs/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int numIdenticalPairs(vector<int>& nums) {
    int cnt[101] = {0};
    int pairs = 0;
    for (const int num : nums) {
      pairs += cnt[num];
      ++cnt[num];
    }
    return pairs;
  }
};
