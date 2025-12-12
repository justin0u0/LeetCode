/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-mentions-per-user/
 * Runtime: 22ms (82.27%)
 */

class Solution {
public:
  vector<int> countMentions(const int n, vector<vector<string>>& events) {
    auto toInt = [](const string& s) {
      int res = 0;
      for (char c : s) {
        res = res * 10 + c - '0';
      }
      return res;
    };

    sort(events.begin(), events.end(), [&](const auto& lhs, const auto& rhs) {
      const int l = toInt(lhs[1]);
      const int r = toInt(rhs[1]);
      if (l != r) {
        return l < r;
      }
      return lhs[0][0] > rhs[0][0];
    });

    vector<int> offline(n, 0);
    vector<int> mentions(n, 0);
    for (const auto& e : events) {
      if (e[0][0] == 'M') {
        const int t = toInt(e[1]);
        if (e[2][0] == 'A') {
          for (int i = 0; i < n; ++i) {
            ++mentions[i];
          }
        } else if (e[2][0] == 'H') {
          for (int i = 0; i < n; ++i) {
            if (offline[i] <= t) {
              ++mentions[i];
            }
          }
        } else {
          stringstream ss(e[2]);
          string s;
          while (ss >> s) {
            ++mentions[toInt(s.substr(2))];
          }
        }
      } else {
        offline[toInt(e[2])] = toInt(e[1]) + 60;
      }
    }
    return mentions;
  }
};
