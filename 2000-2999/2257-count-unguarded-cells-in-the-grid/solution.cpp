/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-unguarded-cells-in-the-grid/
 * Runtime: 46ms (93.81%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  #define EMPTY 0
  #define STOP 1
  #define SEEN_U (1 << 1)
  #define SEEN_D (1 << 2)
  #define SEEN_L (1 << 3)
  #define SEEN_R (1 << 4)
public:
  int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<uint8_t>> cells(m, vector<uint8_t>(n, EMPTY));
    for (const auto& w : walls) {
      cells[w[0]][w[1]] = STOP;
    }

    for (const auto& g : guards) {
      const int x = g[0];
      const int y = g[1];
      cells[x][y] |= STOP;
      for (int i = x - 1; i >= 0 && (cells[i][y] & (STOP | SEEN_U)) == 0; --i) {
        cells[i][y] |= SEEN_U;
      }
      for (int i = x + 1; i < m && (cells[i][y] & (STOP | SEEN_D)) == 0; ++i) {
        cells[i][y] |= SEEN_D;
      }
      for (int i = y - 1; i >= 0 && (cells[x][i] & (STOP | SEEN_L)) == 0; --i) {
        cells[x][i] |= SEEN_L;
      }
      for (int i = y + 1; i < n && (cells[x][i] & (STOP | SEEN_R)) == 0; ++i) {
        cells[x][i] |= SEEN_R;
      }
    }

    int nonGuarded = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (cells[i][j] == EMPTY) {
          ++nonGuarded;
        }
      }
    }
    return nonGuarded;
  }
};
