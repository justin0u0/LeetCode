/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<vector<int>> mergeArrays(const vector<vector<int>>& nums1, const vector<vector<int>>& nums2) {
    const int n = nums1.size();
    const int m = nums2.size();

    vector<vector<int>> arr;
    int i = 0;
    int j = 0;
    while (i < n || j < m) {
      if (i < n && j < m && nums1[i][0] == nums2[j][0]) {
        arr.emplace_back(vector<int>{nums1[i][0], nums1[i][1] + nums2[j][1]});
        ++i;
        ++j;
      } else if (j == m || (i < n && nums1[i][0] < nums2[j][0])) {
        arr.emplace_back(nums1[i]);
        ++i;
      } else {
        arr.emplace_back(nums2[j]);
        ++j;
      }
    }

    return arr;
  }
};
