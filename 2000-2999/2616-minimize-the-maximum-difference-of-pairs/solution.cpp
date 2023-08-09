/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/
 * Runtime: 113ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minimizeMax(vector<int>& nums, int p) {
    sort(nums.begin(), nums.end());
    int l = 0;
    int r = 1e9 + 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      int pairs = 0;
      for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] - nums[i - 1] <= mid) {
          ++pairs;
          ++i;
        }
      }
      if (pairs >= p) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    return r;
  }
};
