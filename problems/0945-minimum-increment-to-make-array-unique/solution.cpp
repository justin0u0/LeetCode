/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-increment-to-make-array-unique/
 * Runtime: 87ms (95.47%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minIncrementForUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int incr = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] <= nums[i - 1]) {
        incr += nums[i - 1] - nums[i] + 1;
        nums[i] = nums[i - 1] + 1;
      }
    }
    return incr;
  }
};
