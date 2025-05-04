/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-equivalent-domino-pairs/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int count[100] = {0};

    int pairs = 0;
    for (const auto& d : dominoes) {
      int id = min(d[0], d[1]) * 9 + max(d[0], d[1]);
      pairs += count[id];
      ++count[id];
    }
    return pairs;
  }
};
