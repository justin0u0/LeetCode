/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-matching-of-players-with-trainers/
 * Runtime: 26ms (82.32%)
 */

class Solution {
public:
  int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());

    const int n = players.size();
    const int m = trainers.size();

    int j = 0;
    int match = 0;
    for (int i = 0; i < n; ++i) {
      while (j < m && players[i] > trainers[j]) {
        ++j;
      }
      if (j != m) {
        ++match;
        ++j;
      }
    }
    return match;
  }
};
