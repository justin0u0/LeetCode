/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sliding-puzzle/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  const int n = 2;
  const int m = 3;
  const int di[4] = {0, 0, 1, -1};
  const int dj[4] = {1, -1, 0, 0};

  inline int minSteps(const vector<vector<int>>& board) {
    // The best heuristic is Manhattan distance + linear conflict AFAIK.
    //
    // I only take Manhattan distance into account as the board is small.

    int steps = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (board[i][j] == 0) {
          continue;
        }
        const int b = board[i][j] - 1;
        const int x = b / m;
        const int y = b % m;

        steps += abs(x - i) + abs(y - j);
      }
    }
    return steps;
  }

  bool ida(vector<vector<int>>& board, int ttl, int skip) {
    int ms = minSteps(board);

    if (ms == 0) {
      return true;
    }
    if (ms > ttl) {
      return false;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (board[i][j] != 0) {
          continue;
        }
        for (int k = 0; k < 4; ++k) {
          // Skip reverse operation
          if (k == skip) {
            continue;
          }

          const int si = i + di[k];
          const int sj = j + dj[k];
          if (si < 0 || si >= n || sj < 0 || sj >= m) {
            continue;
          }
          swap(board[i][j], board[si][sj]);
          if (ida(board, ttl - 1, k ^ 1)) {
            return true;
          }
          swap(board[i][j], board[si][sj]);
        }
      }
    }
    
    return false;
  }
public:
  int slidingPuzzle(vector<vector<int>>& board) {
    const int ms = minSteps(board);
    if (ms == 0) {
      return 0;
    }

    for (int dist = ms; dist < 20; dist++) {
      if (ida(board, dist, -1)) {
        return dist;
      }
    }
    return -1;
  }
};
