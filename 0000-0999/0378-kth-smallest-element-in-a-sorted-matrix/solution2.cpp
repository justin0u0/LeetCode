/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
 * Runtime: 29ms
 * Time Complexity: O(log(D) * N), where D is the maximum difference of all elements
 * Space Complexity: O(1)
 * Description:
 *  Binary search and verify if the element has at least k elements <= the target.
 *  If true, than try another smaller target, else bigger.
 */

class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int l = matrix[0][0];
    int r = matrix.back().back();
    while (l <= r) {
      int mid = (l + r) >> 1;
      int row = 0;
      int col = n - 1;

      // count number of elements that are smaller than or equal to `mid`
      int cnt = 0;

      while (row < n && col >= 0) {
        if (matrix[row][col] <= mid) {
          cnt += col + 1;
          ++row;
        } else {
          --col;
        }
      }

      if (cnt >= k) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return r + 1;
  }
};
