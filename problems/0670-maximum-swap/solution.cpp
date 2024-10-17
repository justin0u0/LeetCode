/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-swap/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maximumSwap(int num) {
    int i;
    int rev = 0;
    pair<int, int> swapAt{-1, -1};
    pair<int, int> swapDigits;
    pair<int, int> maxDigit;
    for (i = 0; num != 0; ++i) {
      const int d = num % 10;
      num /= 10;
      rev = rev * 10 + d;

      if (d < maxDigit.first) {
        swapAt = {i, maxDigit.second};
        swapDigits = {d, maxDigit.first};
      } else if (d > maxDigit.first) {
        maxDigit = {d, i};
      }
    }

    --i;

    int res = 0;
    for (; i >= 0; --i) {
      if (swapAt.first == i) {
        res = res * 10 + swapDigits.second;
      } else if (swapAt.second == i) {
        res = res * 10 + swapDigits.first;
      } else {
        res = res * 10 + rev % 10;
      }
      rev /= 10;
    }
    return res;
  }
};
