/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  char findKthBit(int n, int k) {
    if (n == 1) {
      return '0';
    }

    const int m = 1 << n;
    const int mid = m >> 1;
    if (k < mid) {
      return findKthBit(n - 1, k);
    } else if (k > mid) {
      return findKthBit(n - 1, m - k) ^ 1;
    } else {
      return '1';
    }
  }
};
