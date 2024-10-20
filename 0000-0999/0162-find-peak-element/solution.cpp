/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-peak-element/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    int l = 0;
    int r = nums.size();
    nums.emplace_back(INT_MIN);

    while (l < r) {
      int mid = (l + r) >> 1;

      if (nums[mid] > nums[mid + 1] && (mid == 0 || nums[mid] > nums[mid - 1])) {
        return mid;
      }

      if (nums[mid + 1] > nums[mid]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    return 0;
  }
};
