/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/robot-collisions/
 * Runtime: 142ms (99.62%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> survivedRobotsHealths(const vector<int>& positions, vector<int>& healths, const string& directions) {
    const int n = positions.size();
    vector<int> sorted(positions.begin(), positions.end());
    sort(sorted.begin(), sorted.end());
    vector<int> ordered(n);
    for (int i = 0; i < n; ++i) {
      ordered[lower_bound(sorted.begin(), sorted.end(), positions[i]) - sorted.begin()] = i;
    }

    stack<int> stk;
    for (int i = 0; i < n; ++i) {
      const int j = ordered[i];
      if (directions[j] == 'R') {
        stk.push(j);
      } else {
        while (!stk.empty() && healths[j] > healths[stk.top()]) {
          healths[stk.top()] = 0;
          --healths[j];
          stk.pop();
        }
        if (!stk.empty() && healths[j] < healths[stk.top()]) {
          --healths[stk.top()];
          healths[j] = 0;
        }
        if (!stk.empty() && healths[j] == healths[stk.top()]) {
          healths[stk.top()] = 0;
          healths[j] = 0;
          stk.pop();
        }
      }
    }

    vector<int> answer;
    answer.reserve(n);
    for (int i = 0; i < n; ++i) {
      if (healths[i] != 0) {
        answer.emplace_back(healths[i]);
      }
    }
    return answer;
  }
};
