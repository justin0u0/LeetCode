/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-players-with-zero-or-one-losses/
 * Runtime: 757ms (90.33%)
 */

class Solution {
public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    map<int, int> players;
    for (const vector<int>& match : matches) {
      if (players.find(match[0]) == players.end()) {
        players.emplace(match[0], 0);
      }
      if (players.find(match[1]) == players.end()) {
        players.emplace(match[1], 1);
      } else {
        ++players.at(match[1]);
      }
    }

    vector<vector<int>> answer(2);
    for (const auto& [player, loses] : players) {
      if (loses == 0) {
        answer[0].emplace_back(player);
      } else if (loses == 1) {
        answer[1].emplace_back(player);
      }
    }

    return answer;
  }
};
