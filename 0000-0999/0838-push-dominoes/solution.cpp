/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/push-dominoes/
 * Runtime: 115ms
 */

class Solution {
private:
  bool push(vector<int>& pushes, int i, int k) {
    if ((i > 0 && pushes[i - 1] == k) && (i + 1 == pushes.size() || pushes[i + 1] != -k)) {
      pushes[i] = k + 1;
      return true;
    }
    if ((i + 1 < pushes.size() && pushes[i + 1] == -k) && (i == 0 || pushes[i - 1] != k)) {
      pushes[i] = -(k + 1);
      return true;
    }

    return false;
  }
public:
  string pushDominoes(string& dominoes) {
    int n = dominoes.size();
    vector<int> pushes(n, 0);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (dominoes[i] != '.') {
        if (dominoes[i] == 'L') {
          pushes[i] = -1;
        } else {
          pushes[i] = 1;
        }
        q.push(i);
      }
    }

    for (int k = 1; !q.empty(); ++k) {
      for (int size = q.size(); size > 0; --size) {
        int i = q.front();
        q.pop();
        if (i > 0 && pushes[i - 1] == 0 && push(pushes, i - 1, k)) {
          q.push(i - 1);
        }
        if (i + 1 < n && pushes[i + 1] == 0 && push(pushes, i + 1, k)) {
          q.push(i + 1);
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      if (pushes[i] == 0) {
        dominoes[i] = '.';
      } else if (pushes[i] < 0) {
        dominoes[i] = 'L';
      } else {
        dominoes[i] = 'R';
      }
    }

    return dominoes;
  }
};
