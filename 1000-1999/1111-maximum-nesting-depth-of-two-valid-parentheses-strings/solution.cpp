/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> maxDepthAfterSplit(const string& seq) {
    vector<int> res(seq.length());
    int lt = 0;
    int rt = 0;

    for (int i = 0; i < seq.length(); ++i) {
      if (seq[i] == '(') {
        res[i] = lt;
        lt ^= 1;
      } else {
        res[i] = rt;
        rt ^= 1;
      }
    }

    return res;
  }
};
