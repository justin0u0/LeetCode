/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
    const int n = a.size();
    vector<int> count(n + 1, 0);
    vector<int> res(n);
    int common = 0;
    for (int i = 0; i < n; ++i) {
      if (++count[a[i]] == 2) {
        ++common;
      }
      if (++count[b[i]] == 2) {
        ++common;
      }
      res[i] = common;
    }
    return res;
  }
};
