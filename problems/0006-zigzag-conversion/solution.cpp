/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/zigzag-conversion/
 * Runtime: 3ms (98.92%)
 */

class Solution {
public:
  string convert(string& s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    vector<string> box(numRows);
    int i = 0;
    int j = 0;
    bool down = true;
    for (const char& c : s) {
      box[i].push_back(c);
      if (down) {
        ++i;
      } else {
        --i;
        ++j;
      }
      if (i == numRows - 1) {
        down = false;
      }
      if (i == 0) {
        down = true;
      }
    }

    string answer = "";
    for (const string& row : box) {
      answer += row;
    }
    return answer;
  }
};
