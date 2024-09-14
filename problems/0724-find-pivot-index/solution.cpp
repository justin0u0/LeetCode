/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-pivot-index/
 * Runtime: 9ms (94.34%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    int l = 0;
    int r = accumulate(nums.begin(), nums.end(), 0);
    for (int i = 0; i < nums.size(); ++i) {
      r -= nums[i];
      if (l == r) {
        return i;
      }
      l += nums[i];
    }
    return -1;
  }
};
