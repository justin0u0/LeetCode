/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
 * Runtime: 381ms (98.77%)
 */

class Solution {
private:
  class DJS {
  public:
    vector<int> pa;

    DJS(int n) : pa(vector<int>(n)) {
      for (int i = 0; i < n; ++i) {
        pa[i] = i;
      }
    }

    int find(int x) {
      if (pa[x] == x) {
        return x;
      }
      pa[x] = find(pa[x]);
      return pa[x];
    }

    void merge(int x, int y) {
      int fx = find(x);
      int fy = find(y);
      if (fx != fy) {
        pa[fx] = pa[fy];
      }
    }
  };
public:
  int minScore(int n, vector<vector<int>>& roads) {
    DJS d(n + 1);
    vector<int> minVal(n + 1, INT_MAX);
    for (const vector<int>& road : roads) {
      d.merge(road[0], road[1]);
      minVal[road[0]] = min(minVal[road[0]], road[2]);
    }

    int f = d.find(1);
    int answer = minVal[1];
    for (int i = 2; i <= n; ++i) {
      if (f == d.find(i)) {
        answer = min(answer, minVal[i]);
      }
    }
    return answer;
  }
};
