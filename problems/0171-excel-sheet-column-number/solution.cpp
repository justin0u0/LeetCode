/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/excel-sheet-column-number/
 * Runtime: 0ms
 */

class Solution {
public:
  int titleToNumber(string columnTitle) {
    int column = 0;
    for (const char& c : columnTitle) {
      column = column * 26 + (c - 'A' + 1);
    }

    return column;
  }
};
