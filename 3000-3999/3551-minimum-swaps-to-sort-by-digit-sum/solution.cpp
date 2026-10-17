/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/
 * Runtime: 586ms (41.05%)
 */

class Solution {
public:
  int minSwaps(const vector<int>& nums) {
    const int n = nums.size();

    auto indices = views::iota(0u, nums.size()) | ranges::to<vector>();
    ranges::sort(indices, {}, [&](size_t i) {
      int digits = 0;
      for (int x = nums[i]; x > 0; x /= 10) {
        digits += x % 10;
      }
      return pair{digits, nums[i]};
    });

    int swaps = 0;
    for (int i = 0; i < n; ++i) {
      while (indices[i] != i) {
        swap(indices[i], indices[indices[i]]);
        ++swaps;
      }
    }
    return swaps;
  }
};
