/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/
 * Runtime: 108ms (94.58%)
 */

class Solution {
public:
  long long minSum(const vector<int>& nums1, const vector<int>& nums2) {
    long long ls = 0;
    long long rs = 0;
    int lz = 0;
    int rz = 0;
    for (int num : nums1) {
      ls += num;
      if (num == 0) {
        ++lz;
      }
    }
    for (int num : nums2) {
      rs += num;
      if (num == 0) {
        ++rz;
      }
    }

    ls += lz;
    rs += rz;

    if (ls == rs) {
      return ls;
    }
    if (ls > rs && rz != 0) {
      return ls;
    }
    if (rs > ls && lz != 0) {
      return rs;
    }
    return -1;
  }
};
