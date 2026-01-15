/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
    sort(hBars.begin(), hBars.end());
    sort(vBars.begin(), vBars.end());

    int cont = 1;
    int hMax = 1;
    for (int i = 1; i < hBars.size(); ++i) {
      if (hBars[i] == hBars[i - 1] + 1) {
        ++cont;
      } else {
        cont = 1;
      }
      hMax = max(hMax, cont);
    }

    cont = 1;
    int vMax = 1;
    for (int i = 1; i < vBars.size(); ++i) {
      if (vBars[i] == vBars[i - 1] + 1) {
        ++cont;
      } else {
        cont = 1;
      }
      vMax = max(vMax, cont);
    }

    const int len = min(hMax, vMax) + 1;
    return len * len;
  }
};
