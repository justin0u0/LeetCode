/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/
 * Runtime: 4ms (73.62%)
 */

class Solution {
public:
  int maxTotalFruits(const vector<vector<int>>& fruits, int startPos, int k) {
    const int n = fruits.size();

    int maxTotal = 0;

    {
      int total = 0;
      for (int i = 0; i < n; ++i) {
        if (fruits[i][0] < startPos) {
          total += fruits[i][1];
        }
      }

      int j = 0;
      for (int i = 0; i < n; ++i) {
        if (fruits[i][0] >= startPos && fruits[i][0] <= startPos + k) {
          total += fruits[i][1];
          while (j < n && fruits[j][0] < startPos && (startPos - fruits[j][0]) * 2 + fruits[i][0] - startPos > k) {
            total -= fruits[j][1];
            ++j;
          }
          maxTotal = max(maxTotal, total);
        }
      }
    }

    {
      int total = 0;
      for (int i = n - 1; i >= 0; --i) {
        if (fruits[i][0] > startPos) {
          total += fruits[i][1];
        }
      }

      int j = n - 1;
      for (int i = n - 1; i >= 0; --i) {
        if (fruits[i][0] <= startPos && fruits[i][0] >= startPos - k) {
          total += fruits[i][1];
          while (j >= 0 && fruits[j][0] > startPos && (fruits[j][0] - startPos) * 2 + startPos - fruits[i][0] > k) {
            total -= fruits[j][1];
            --j;
          }
          maxTotal = max(maxTotal, total);
        }
      }
    }

    return maxTotal;
  }
};
