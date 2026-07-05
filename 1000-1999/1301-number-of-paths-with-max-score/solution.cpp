/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-paths-with-max-score/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  inline static constexpr int mod = 1e9 + 7;
public:
  vector<int> pathsWithMaxScore(const vector<string>& board) {
    const auto n = board.size();

    vector<vector<int>> best(n + 1, vector<int>(n + 1, -0x3f3f3f3f));
    vector<vector<unsigned>> path(n + 1, vector<unsigned>(n + 1, 0));
    best[n][n] = 0;
    path[n][n] = 1;

    auto trans = [&](int i, int j, int gain) {
      best[i][j] = max(best[i + 1][j + 1], max(best[i][j + 1], best[i + 1][j]));
      path[i][j] = (
        (best[i + 1][j + 1] == best[i][j]) * path[i + 1][j + 1] +
        (best[i][j + 1] == best[i][j]) * path[i][j + 1] + 
        (best[i + 1][j] == best[i][j]) * path[i + 1][j]
      ) % mod;
      best[i][j] += gain;
    };

    for (int i = n - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        if (board[i][j] >= '0' && board[i][j] <= '9') {
          trans(i, j, board[i][j] - '0');
        } else if (board[i][j] == 'S' || board[i][j] == 'E') {
          trans(i, j, 0);
        }
      }
    }

    return {max(0, best[0][0]), (int)path[0][0]};
  }
};
