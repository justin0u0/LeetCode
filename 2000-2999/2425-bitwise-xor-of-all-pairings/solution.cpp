/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/bitwise-xor-of-all-pairings/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int res = 0;
    if (nums1.size() & 1) {
      for (int num : nums2) {
        res ^= num;
      }
    }
    if (nums2.size() & 1) {
      for (int num : nums1) {
        res ^= num;
      }
    }
    return res;
  }
};
