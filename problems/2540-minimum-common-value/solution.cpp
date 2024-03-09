/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-common-value/
 * Runtime: 34ms (99.13%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int getCommon(const vector<int>& nums1, const vector<int>& nums2) {
    int j = 0;
    for (int num : nums1) {
      while (j < nums2.size() && nums2[j] < num) {
        ++j;
      }
      if (j == nums2.size()) {
        return -1;
      }
      if (nums2[j] == num) {
        return num;
      }
    }
    return -1;
  }
};
