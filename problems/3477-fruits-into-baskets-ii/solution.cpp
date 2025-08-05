/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/fruits-into-baskets-ii/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int placed = 0;
    for (int i = 0; i < fruits.size(); ++i) {
      for (int j = 0; j < baskets.size(); ++j) {
        if (baskets[j] >= fruits[i]) {
          baskets[j] = 0;
          ++placed;
          break;
        }
      }
    }
    return fruits.size() - placed;
  }
};
