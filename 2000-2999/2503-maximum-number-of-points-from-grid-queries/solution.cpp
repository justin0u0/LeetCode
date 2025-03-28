/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/
 * Runtime: 107ms (51.81%)
 */

class Solution {
private:
  struct Cell {
    int i;
    int j;
    int val;

    bool operator<(const Cell& rhs) const {
      return val > rhs.val;
    }
  };
public:
  vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    const int k = queries.size();
    vector<pair<int, int>> qarr(k);
    for (int i = 0; i < k; ++i) {
      qarr[i] = {queries[i], i};
    }
    sort(qarr.begin(), qarr.end());

    const int n = grid.size();
    const int m = grid[0].size();
    const int di[] = {1, -1, 0, 0};
    const int dj[] = {0, 0, 1, -1};

    vector<int> result(k);

    priority_queue<Cell> pq;
    pq.push({0, 0, grid[0][0]});
    grid[0][0] = 0;

    int cells = 0;

    for (const auto [cap, qid] : qarr) {
      while (!pq.empty() && pq.top().val < cap) {
        Cell c = pq.top();
        pq.pop();
        ++cells;

        for (int i = 0; i < 4; ++i) {
          const int i2 = c.i + di[i];
          const int j2 = c.j + dj[i];

          if (i2 < 0 || j2 < 0 || i2 >= n || j2 >= m || grid[i2][j2] == 0) {
            continue;
          }
          pq.push({i2, j2, grid[i2][j2]});
          grid[i2][j2] = 0;
        }
      }

      result[qid] = cells;
    }

    return result;
  }
};
