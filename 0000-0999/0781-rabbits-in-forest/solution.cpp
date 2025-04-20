/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/rabbits-in-forest/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int numRabbits(vector<int>& answers) {
    vector<int> count(1001, 0);
    for (const int v : answers) {
      ++count[v];
    }

    int total = count[0];
    for (int i = 1; i <= 1000; ++i) {
      if (count[i] != 0) {
        total += (i + 1) * ((count[i] - 1) / (i + 1) + 1);
      }
    }
    return total;
  }
};
