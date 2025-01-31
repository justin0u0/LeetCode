/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/making-a-large-island/
 * Runtime: 290ms (39.45%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  int pa[250001];
  int sz[250001];

  int find(int x) {
    if (pa[x] == x) {
      return x;
    }

    return (pa[x] = find(pa[x]));
  }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      if (sz[y] < sz[x]) {
        pa[y] = x;
        sz[x] += sz[y];
      } else {
        pa[x] = y;
        sz[y] += sz[x];
      }
    }
  }
public:
  int largestIsland(const vector<vector<int>>& grid) {
    const int n = grid.size();
    const int m = grid[0].size();
    
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 0) {
          continue;
        }
        const int f = i * n + j;
        pa[f] = f;
        sz[f] = 1;
        if (i != 0 && grid[i - 1][j] == 1) {
          merge(f, f - n);
        }
        if (j != 0 && grid[i][j - 1] == 1) {
          merge(f, f - 1);
        }
      }
    }

    const int di[] = {1, -1, 0, 0};
    const int dj[] = {0, 0, 1, -1};
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] != 0) {
          mx = max(mx, sz[find(i * n + j)]);
          continue;
        }

        unordered_map<int, int> um;
        for (int k = 0; k < 4; ++k) {
          int i2 = i + di[k];
          int j2 = j + dj[k];
          if (i2 < 0 || i2 >= n || j2 < 0 || j2 >= m || grid[i2][j2] == 0) {
            continue;
          }
          const int f = find(i2 * n + j2);
          um.emplace(f, sz[f]);
        }

        int sum = 0;
        for (auto [k, v] : um) {
          sum += v;
        }
        mx = max(mx, sum + 1);
      }
    }
    return mx;
  }
};
