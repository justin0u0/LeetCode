/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maxCandies(vector<int>& status, const vector<int>& candies, const vector<vector<int>>& keys, const vector<vector<int>>& containedBoxes, const vector<int>& initialBoxes) {
    // 1: open but not found
    // 2: found but close
    queue<int> q;
    for (const int b : initialBoxes) {
      if (status[b] == 1) {
        status[b] = -1;
        q.push(b);
      } else {
        status[b] = 2;
      }
    }

    int sum = 0;
    while (!q.empty()) {
      const int u = q.front();
      q.pop();

      sum += candies[u];

      for (const int v : keys[u]) {
        if (status[v] == 2) {
          status[v] = -1;
          q.push(v);
        } else if (status[v] != -1) {
          status[v] = 1;
        }
      }
      for (const int v : containedBoxes[u]) {
        if (status[v] == 1) {
          status[v] = -1;
          q.push(v);
        } else if (status[v] != -1) {
          status[v] = 2;
        }
      }
    }

    return sum;
  }
};
