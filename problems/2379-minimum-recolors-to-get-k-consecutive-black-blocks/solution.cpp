/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minimumRecolors(const string& blocks, const int k) {
    int w = 0;
    for (int i = 0; i < k; ++i) {
      if (blocks[i] == 'W') {
        ++w;
      }
    }

    int mn = w;
    for (int i = k; i < blocks.size(); ++i) {
      if (blocks[i - k] == 'W') {
        --w;
      }
      if (blocks[i] == 'W') {
        ++w;
      }
      mn = min(mn, w);
    }
    return mn;
  }
};
