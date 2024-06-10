/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/height-checker/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int heightChecker(const vector<int>& heights) {
    vector<int> expected(heights.begin(), heights.end());
    sort(expected.begin(), expected.end());
    int res = 0;
    for (int i = 0; i < heights.size(); ++i) {
      if (heights[i] != expected[i]) {
        ++res;
      }
    }
    return res;
  }
};
