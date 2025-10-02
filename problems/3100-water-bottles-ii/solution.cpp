/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/water-bottles-ii/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maxBottlesDrunk(int numBottles, int numExchange) {
    int empty = 0;
    int drunk = 0;
    while (numBottles != 0) {
      drunk += numBottles;
      empty += numBottles;
      numBottles = 0;
      if (empty >= numExchange) {
        empty -= numExchange;
        ++numBottles;
        ++numExchange;
      }
    }
    return drunk;
  }
};
