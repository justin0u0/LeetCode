/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-product-of-three-numbers/
 * Runtime: 1ms (71.43%)
 */

class Solution {
public:
  int maximumProduct(const vector<int>& nums) {
    int pmx[3] = {INT_MIN, INT_MIN, INT_MIN};
    int nmn[2] = {0};
    for (int num : nums) {
      if (num > pmx[0]) {
        pmx[2] = pmx[1];
        pmx[1] = pmx[0];
        pmx[0] = num;
      } else if (num > pmx[1]) {
        pmx[2] = pmx[1];
        pmx[1] = num;
      } else if (num > pmx[2]) {
        pmx[2] = num;
      }
      if (num < 0) {
        if (num < nmn[0]) {
          nmn[1] = nmn[0];
          nmn[0] = num;
        } else if (num < nmn[1]) {
          nmn[1] = num;
        }
      }
    }

    if (pmx[0] < 0) {
      return pmx[0] * pmx[1] * pmx[2];
    }
    return max(pmx[0] * pmx[1] * pmx[2], pmx[0] * nmn[0] * nmn[1]);
  }
};
