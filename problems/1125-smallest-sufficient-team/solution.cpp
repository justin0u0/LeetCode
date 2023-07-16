/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/smallest-sufficient-team/
 * Runtime: 32ms (95.16%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> smallestSufficientTeam(const vector<string>& reqSkills, const vector<vector<string>>& people) {
    int n = reqSkills.size();
    unordered_map<string, int> reqSkillIds;
    for (int i = 0; i < n; ++i) {
      reqSkillIds.emplace(reqSkills[i], i);
    }

    int m = 1 << n;
    vector<int> dp(m, 0x3f3f3f3f);
    dp[0] = 0;
    vector<pair<int, int>> last(m);
    for (int i = 0; i < people.size(); ++i) {
      int skill = 0;
      for (const string& s : people[i]) {
        skill |= (1 << reqSkillIds[s]);
      }

      for (int j = 0; j < m; ++j) {
        int k = j | skill;
        if (k != j && dp[k] > dp[j] + 1) {
          dp[k] = dp[j] + 1;
          last[k] = {j, i};
        }
      }
    }

    vector<int> answer;
    auto x = last[m - 1];
    while (x.first != 0) {
      answer.emplace_back(x.second);
      x = last[x.first];
    }
    answer.emplace_back(x.second);
    return answer;
  }
};
