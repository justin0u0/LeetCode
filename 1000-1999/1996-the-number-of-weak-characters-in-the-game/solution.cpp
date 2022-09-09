/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
 * Runtime: 656ms
 */

class Solution {
public:
  int numberOfWeakCharacters(vector<vector<int>>& properties) {
    sort(properties.begin(), properties.end(), [](const vector<int>& lhs, const vector<int>& rhs) -> bool {
      if (lhs[0] == rhs[0]) {
        return lhs[1] < rhs[1];
      }
      return lhs[0] > rhs[0];
    });

    int maxDef = 0;
    int answer = 0;
    for (const vector<int>& property : properties) {
      if (maxDef > property[1]) {
        ++answer;
      }
      maxDef = max(maxDef, property[1]);
    }

    return answer;
  }
};
