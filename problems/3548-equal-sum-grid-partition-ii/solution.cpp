/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/equal-sum-grid-partition-ii/
 * Runtime: 1731ms (24.61%)
 */

class Solution {
private:
  bool partition(const vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    long long total = 0;
    unordered_multiset<int> s2;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        total += grid[i][j];
        s2.emplace(grid[i][j]);
      }
    }

    long long partial = 0;
    unordered_set<int> s;
    for (int i = 0; i + 1 < m; ++i) {
      for (int j = 0; j < n; ++j) {
        partial += grid[i][j];
        if (i > 0) {
          s.emplace(grid[i][j]);
        }
        if (i < m - 1) {
          s2.erase(s2.find(grid[i][j]));
        }
      }

      if (i == 0) {
        s.emplace(grid[0][0]);
        s.emplace(grid[0][n - 1]);
      }
      if (i == 1) {
        for (int j = 1; j + 1 < n; ++j) {
          s.emplace(grid[0][j]);
        }
      }
      if (i == m - 2) {
        for (int j = 1; j + 1 < n; ++j) {
          s2.erase(s2.find(grid[m - 1][j]));
        }
      }

      const long long sum = partial + partial;
      if (sum == total) {
        return true;
      }
      if (sum > total && sum - total <= 1e5 && s.find(sum - total) != s.end()) {
        return n > 1 || grid[0][0] == sum - total || grid[i][0] == sum - total;
      }
      if (sum < total && total - sum <= 1e5 && s2.find(total - sum) != s2.end()) {
        return n > 1 || grid[m - 1][0] == total - sum || grid[i + 1][0] == total - sum;
      }
    }

    return false;
  }
public:
  bool canPartitionGrid(vector<vector<int>>& grid) {
    if (partition(grid)) {
      return true;
    }

    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<int>> transpose(n, vector<int>(m));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        transpose[j][i] = grid[i][j];
      }
    }

    return partition(transpose);
  }
};
