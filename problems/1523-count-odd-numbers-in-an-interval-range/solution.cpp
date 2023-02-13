/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int countOdds(int low, int high) {
    return (high + 1) / 2 - low / 2;
  }
};
