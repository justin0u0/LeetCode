/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [](int l, int r) {
      const int x = __builtin_popcount(l);
      const int y = __builtin_popcount(r);
      return x < y || (x == y && l < r);
    });
    return arr;
  }
};
