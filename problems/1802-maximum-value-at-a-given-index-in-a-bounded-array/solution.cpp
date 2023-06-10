/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  inline long long sum(int l, int r, int v) {
    int len = min(v, r - l + 1);
    return (long long)(v + v - len + 1) * len / 2;
  }
public:
  int maxValue(int n, int index, int maxSum) {
    maxSum -= n;

    int l = 0;
    int r = maxSum;
    while (l <= r) {
      int v = (l + r) >> 1;
      long long total = sum(0, index, v) + sum(index, n - 1, v) - v;
      if (total > maxSum) {
        r = v - 1;
      } else {
        l = v + 1;
      }
    }

    return l;
  }
};
