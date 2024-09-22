/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/move-zeroes/
 * Runtime: 4ms (99.40%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int j = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) {
        swap(nums[i], nums[j]);
        ++j;
      }
    }
  }
};
