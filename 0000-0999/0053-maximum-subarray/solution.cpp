/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-subarray/
 * Runtime: 66ms (92.99%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    // Using divide and conquer.
    //
    // Time complexity: T(N) = 2T(N/2) + O(1) → O(N)

    function<array<int, 4>(int, int)> dnc = [&](int l, int r) -> array<int, 4> {
      // Return maximum sum of subarray {arr[l:x], arr[x:r], arr[x:y] arr[l:r]},
      // where x, y ∈ [l, r]
      if (l == r) {
        return {nums[l], nums[l], nums[l], nums[l]};
      }

      int mid = (l + r) >> 1;
      auto larr = dnc(l, mid);
      auto rarr = dnc(mid + 1, r);

      return {
        max(larr[0], larr[3] + rarr[0]),
        max(rarr[1], rarr[3] + larr[1]),
        max(max(larr[2], rarr[2]), larr[1] + rarr[0]),
        larr[3] + rarr[3]
      };
    };
    
    auto res = dnc(0, nums.size() - 1);
    return max(max(res[0], res[1]), max(res[2], res[3]));
  }
};
