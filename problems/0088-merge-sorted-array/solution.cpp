/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/merge-sorted-array/
 * Runtime: 0ms
 */

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int cur = m + n - 1;
    --m;
    --n;
    while (m >= 0 || n >= 0) {
      if (n < 0 || (m >= 0 && nums1[m] > nums2[n])) {
        nums1[cur--] = nums1[m--];
      } else {
        nums1[cur--] = nums2[n--];
      }
    }
  }
};
