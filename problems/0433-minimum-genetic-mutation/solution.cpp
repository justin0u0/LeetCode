/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-genetic-mutation/
 * Runtime: 0ms (100.0%)
 */

class Solution {
private:
  const int length = 8;
public:
  int minMutation(string& start, string& end, vector<string>& bank) {
    vector<bool> vis(bank.size(), false);

    queue<string> q;
    queue<string> qNext;
    q.push(start);

    for (int dist = 0; !q.empty(); ++dist) {
      while (!q.empty()) {
        string s = q.front();
        q.pop();

        if (s == end) {
          return dist;
        }

        for (int i = 0; i < bank.size(); ++i) {
          if (!vis[i]) {
            int diff = 0;
            for (int j = 0; j < length; ++j) {
              if (s[j] != bank[i][j]) {
                ++diff;
              }
            }

            if (diff == 1) {
              vis[i] = true;
              qNext.push(bank[i]);
            }
          }
        }
      }
      swap(q, qNext);
    }

    return -1;
  }
};
