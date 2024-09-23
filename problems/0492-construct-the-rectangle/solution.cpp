/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/construct-the-rectangle/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> constructRectangle(int area) {
    int x = area;
    int y = 1;
    for (int i = 2; i * i <= area; ++i) {
      if (area % i == 0) {
        x = area / i;
        y = i;
      }
    }
    return {x, y};
  }
};
