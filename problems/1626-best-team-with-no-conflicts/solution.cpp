/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/best-team-with-no-conflicts/
 * Runtime: 51ms (98.38%)
 */

class Solution {
public:
  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    int n = scores.size();
    vector<pair<int, int>> data(n);
    for (int i = 0; i < n; ++i) {
      data[i] = {ages[i], scores[i]};
    }
    sort(data.begin(), data.end());

    map<int, int> box;
    box.emplace(0, 0);

    int answer = 0;
    for (int i = 0; i < n; ++i) {
      int score = data[i].second;
      int maxScore = score + prev(box.upper_bound(score))->second;

      auto it = box.find(score);
      if (it != box.end() && it->second < maxScore) {
        it->second = maxScore;
      } else {
        it = box.emplace(score, maxScore).first;
      }

      ++it;
      while (it != box.end()) {
        if (it->second <= maxScore) {
          auto it2 = it;
          ++it;
          box.erase(it2);
        } else {
          ++it;
        }
      }

      answer = max(answer, maxScore);
    }
    return answer;
  }
};
