/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/search-a-2d-matrix/
 * Runtime: 4ms
 */

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int l = 0;
    int r = n * m;

    while (l < r) {
      int mid = (l + r) >> 1;
      cout << mid << ' ' << mid / n << ' ' << mid % n << endl;

      int val = matrix[mid / m][mid % m];
      if (val == target) {
        return true;
      }

      if (val < target) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    return false;
  }
};
