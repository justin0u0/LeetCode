/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/squares-of-a-sorted-array/
 * Runtime: 11ms (98.91%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> sortedSquares(vector<int>& nums) {
    const int n = nums.size();
    int j = 0;
    while (j < n && nums[j] < 0) {
      ++j;
    }
    int i = j - 1;

    vector<int> sorted;
    sorted.reserve(n);
    while (j < n || i >= 0) {
      if (j >= n || (i >= 0 && nums[i] * nums[i] < nums[j] * nums[j])) {
        sorted.emplace_back(nums[i] * nums[i]);
        --i;
      } else {
        sorted.emplace_back(nums[j] * nums[j]);
        ++j;
      }
    }
    return sorted;
  }
};
