/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-good-numbers/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;

  long long pow(long long a, long long p) {
    long long res = 1;
    while (p != 0) {
      if (p & 1) {
        res = res * a % mod;
      }
      a = a * a % mod;
      p >>= 1;
    }
    return res;
  }
public:
  int countGoodNumbers(long long n) {
    return pow(5, (n - 1) / 2 + 1) * pow(4, n / 2) % mod;
  }
};
