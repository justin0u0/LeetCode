/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/delete-columns-to-make-sorted/
 * Runtime: 45ms (86.13%)
 */

class Solution {
public:
  int minDeletionSize(vector<string>& strs) {
    int n = strs.size();
    int m = strs[0].size();

    int answer = 0;
    for (int j = 0; j < m; ++j) {
      bool sorted = true;
      for (int i = 1; sorted && i < n; ++i) {
        if (strs[i][j] < strs[i - 1][j]) {
          sorted = false;
        }
      }
      if (!sorted) {
        ++answer;
      }
    }

    return answer;
  }
}
