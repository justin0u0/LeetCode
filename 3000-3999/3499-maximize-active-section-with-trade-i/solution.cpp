/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximize-active-section-with-trade-i/
 * Runtime: 18ms (100.00%)
 */

class Solution {
public:
  int maxActiveSectionsAfterTrade(const string& s) {
    int z = 0;
    int lastz = INT_MIN;
    int maxz = 0;
    int o = 0;
    for (const auto c : s) {
      if (c == '0') {
        ++z;
      } else {
        ++o;
        if (z > 0) {
          maxz = max(maxz, lastz + z);
          lastz = z;
          z = 0;
        }
      }
    }
    if (z > 0) {
      maxz = max(maxz, lastz + z);
    }
    return o + maxz;
  }
};
