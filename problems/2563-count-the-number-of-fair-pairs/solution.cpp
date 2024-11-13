/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-the-number-of-fair-pairs/
 * Runtime: 21ms (98.81%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());

    auto count = [&](int cap) {
      long long pairs = 0;
      int j = nums.size() - 1;

      for (int i = 0; i < nums.size(); ++i) {
        while (i < j && nums[i] + nums[j] > cap) {
          --j;
        }
        if (i >= j) {
          break;
        }

        pairs += j - i;
      }
      return pairs;
    };

    return count(upper) - count(lower - 1);
  }
};
