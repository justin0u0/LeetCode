/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sum-of-k-mirror-numbers/
 * Runtime: 341ms (58.77%)
 */

class Solution {
private:
  inline long long rev(long long x) {
    long long y = 0;
    while (x != 0) {
      y = y * 10 + x % 10;
      x /= 10;
    }
    return y;
  }

  inline bool check(long long x, int k) {
    string s;
    while (x != 0) {
      s += (char)(x % k + '0');
      x /= k;
    }

    const int n = s.length();
    for (int i = 0; i < n / 2; ++i) {
      if (s[i] != s[n - i - 1]) {
        return false;
      }
    }
    return true;
  }
public:
  long long kMirror(const int k, int n) {
    long long res = 0;
    for (int i = 1; i < 10; ++i) {
      if (check(i, k)) {
        res += i;
        if (--n == 0) {
          return res;
        }
      }
    }

    for (long long base = 1; ; base *= 10) {
      // [base, base * 10)
      for (int i = base; i < base * 10; ++i) {
        long long x = i * base * 10 + rev(i);
        if (check(x, k)) {
          res += x;
          if (--n == 0) {
            return res;
          }
        }
      }
      for (int i = base; i < base * 10; ++i) {
        for (int j = 0; j < 10; ++j) {
          long long x = i * base * 100 + j * base * 10 + rev(i);
          if (check(x, k)) {
            res += x;
            if (--n == 0) {
              return res;
            }
          }
        }
      }
    }

    return -1;
  }
};
