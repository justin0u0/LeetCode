/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/construct-uniform-parity-array-ii/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool uniformArray(const vector<int>& nums1) {
    int minE = INT_MAX;
    int minO = INT_MAX;
    int o = 0;
    for (int num : nums1) {
      if (num & 1) {
        ++o;
        minO = min(minO, num);
      } else {
        minE = min(minE, num);
      }
    }
    return o == 0 || minE > minO;
  }
};
