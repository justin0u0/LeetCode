/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/spiral-matrix-iv/
 * Runtime: 141ms (95.67%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    vector<vector<int>> mat(m, vector<int>(n, -1));
    int x = 0;
    int y = 0;
    int d = 0;
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};
    
    for (ListNode* cur = head; cur != nullptr; cur = cur->next) {
      mat[x][y] = cur->val;

      int x2 = x + dx[d];
      int y2 = y + dy[d];
      if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || mat[x2][y2] != -1) {
        d = (d + 1) % 4;
        x2 = x + dx[d];
        y2 = y + dy[d];
      }
      x = x2;
      y = y2;
    }

    return mat;
  }
};
