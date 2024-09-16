/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-time-difference/
 * Runtime: 4ms (97.96%)
 */

class Solution {
private:
  bool vis[1440];
public:
  int findMinDifference(vector<string>& timePoints) {
    memset(vis, false, sizeof(vis));

    int last = 0;
    for (const auto& tp : timePoints) {
      const int x = ((tp[0] - '0') * 10 + tp[1] - '0') * 60 + (tp[3] - '0') * 10 + tp[4] - '0';
      if (vis[x]) {
        return 0;
      }

      vis[x] = true;
      last = max(last, x);
    }

    int answer = INT_MAX;
    for (int i = 0; i < 1440; ++i) {
      if (vis[i]) {
        if (i > last) {
          answer = min(answer, i - last);
        } else {
          answer = min(answer, 1440 - last + i);
        }
        last = i;
      }
    }
    return answer;
  }
};
