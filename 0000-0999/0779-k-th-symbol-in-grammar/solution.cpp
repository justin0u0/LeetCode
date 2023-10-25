/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/k-th-symbol-in-grammar/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int kthGrammar(int n, int k) {
    --k;

    bool x = false;
    while (k != 0 && n > 0) {
      if (k & 1) {
        x ^= 1;
      }
      k >>= 1;
      --n;
    }
    return x;
  }
};
