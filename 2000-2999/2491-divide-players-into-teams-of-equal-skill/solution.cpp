/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/
 * Runtime: 49ms (97.40%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long dividePlayers(const vector<int>& skill) {
    const int total = accumulate(skill.begin(), skill.end(), 0);
    if (total % (skill.size() / 2) != 0) {
      return -1;
    }

    const int target = total / (skill.size() / 2);

    unordered_multiset<int> s;
    long long answer = 0;
    for (int val : skill) {
      auto it = s.find(target - val);
      if (it != s.end()) {
        answer += val * (target - val);
        s.erase(it);
      } else {
        s.emplace(val);
      }
    }
    if (!s.empty()) {
      return -1;
    }
    return answer;
  }
};
