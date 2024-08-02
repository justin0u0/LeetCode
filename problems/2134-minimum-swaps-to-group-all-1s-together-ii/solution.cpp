/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
 * Runtime: 45ms (99.61%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minSwaps(const vector<int>& nums) {
    int ones = 0;
    for (int num : nums) {
      if (num == 1) {
        ++ones;
      }
    }
    if (ones == 0 || ones == nums.size()) {
      return 0;
    }

    int z = 0;
    int j;
    for (j = 0; j < ones; ++j) {
      if (nums[j] == 0) {
        ++z;
      }
    }

    const int n = nums.size();
    int swaps = z;
    for (int i = 0; i < n; ++i) {
      if (nums[j] == 0) {
        ++z;
      }
      if (nums[i] == 0) {
        --z;
      }
      swaps = min(swaps, z);
      j = (j + 1) % n;
    }
    return swaps;
  }
};
