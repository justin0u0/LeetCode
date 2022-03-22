/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
 * Runtime: 46ms
 */

class Solution {
public:
  string getSmallestString(int n, int k) {
    k -= n;

    string s(n, 'a');
    for (int i = n - 1; i >= 0; --i) {
      int val = min(k, 25);
      k -= val;
      s[i] += val;

      if (k == 0) break;
    }

    return s;
  }
};
