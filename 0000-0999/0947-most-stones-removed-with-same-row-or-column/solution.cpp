/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
 * Runtime: 44ms (98.63%)
 */

class Solution {
private:
  vector<int> pa;

  int findset(int x) {
    return pa[x] == x ? x : (pa[x] = findset(pa[x]));
  }

  void merge(int x, int y) {
    int fx = findset(x);
    int fy = findset(y);
    pa[fx] = fy;
  }
public:
  int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    pa = vector<int>(n);
    for (int i = 0; i < n; ++i) {
      pa[i] = i;
    }

    unordered_map<int, int> rows;
    unordered_map<int, int> cols;
    for (int i = 0; i < n; ++i) {
      int x = stones[i][0];
      int y = stones[i][1];

      auto rit = rows.find(x);
      if (rit != rows.end()) {
        merge(rit->second, i);
      } else {
        rows.emplace(x, i);
      }

      auto cit = cols.find(y);
      if (cit != cols.end()) {
        merge(cit->second, i);
      } else {
        cols.emplace(y, i);
      }
    }

    int answer = n;
    for (int i = 0; i < n; ++i) {
      if (pa[i] == i) {
        --answer;
      }
    }

    return answer;
  }
};
