/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string getHappyString(int n, int k) {
    if (n == 0) {
      return "";
    }

    int m = 1 << (n - 1);
    if (3 * m < k) {
      return "";
    }

    --k;

    string s;
    if (k < m) {
      s += 'a';
    } else if (k < 2 * m) {
      s += 'b';
    } else {
      s += 'c';
    }
    k %= m;
    m >>= 1;

    while (m != 0) {
      switch (s.back()) {
        case 'a':
          s += (k < m) ? 'b' : 'c';
          break;
        case 'b':
          s += (k < m) ? 'a' : 'c';
          break;
        case 'c':
          s += (k < m) ? 'a' : 'b';
          break;
      }
      k %= m;
      m >>= 1;
    }

    return s;
  }
};
