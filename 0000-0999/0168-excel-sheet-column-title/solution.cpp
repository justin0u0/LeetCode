/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/excel-sheet-column-title/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string convertToTitle(int columnNumber) {
    string answer;
    while (columnNumber != 0) {
      --columnNumber;
      answer.push_back(columnNumber % 26 + 'A');
      columnNumber /= 26;
    }
    reverse(answer.begin(), answer.end());
    return answer;
  }
};
