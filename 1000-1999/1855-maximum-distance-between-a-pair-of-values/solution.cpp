/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    const int m = nums1.size();
    const int n = nums2.size();

    int j = 0;
    int dist = 0;
    for (int i = 0; i < m; ++i) {
      while (j < n && nums1[i] <= nums2[j]) {
        ++j;
      }
      if (j >= n || nums1[i] > nums2[j]) {
        dist = max(dist, j - i - 1);
      }
    }
    return dist;
  }
};
