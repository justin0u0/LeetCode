/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int countPrimeSetBits(int left, int right) {
    vector<bool> prime(32, false);
    for (const auto p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}) {
      prime[p] = true;
    }

    int res = 0;
    for (int i = left; i <= right; ++i) {
      auto count = __builtin_popcount(i);
      if (prime[count]) {
        ++res;
      }
    }
    return res;
  }
};
