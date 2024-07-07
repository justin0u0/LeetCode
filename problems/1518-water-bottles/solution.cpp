/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/water-bottles/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    int empty = 0;
    int sum = 0;
    while (numBottles != 0) {
      sum += numBottles;
      empty += numBottles;
      numBottles = empty / numExchange;
      empty %= numExchange;
    }
    return sum;
  }
};
