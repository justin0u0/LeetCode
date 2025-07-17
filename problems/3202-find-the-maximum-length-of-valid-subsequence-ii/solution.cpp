/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/
 * Runtime: 75ms (99.41%)
 */

class Solution {
public:
  int maximumLength(vector<int>& nums, int k) {
    vector<vector<int>> arr(k);
    for (int i = 0; i < nums.size(); ++i) {
      arr[nums[i] % k].emplace_back(i);
    }

    int res = 2;
    for (int i = 0; i < k; ++i) {
      const int n = arr[i].size();
      res = max(res, n);

      for (int j = i + 1; j < k; ++j) {
        const int m = arr[j].size();

        int flag = -1;
        int u = 0;
        int v = 0;
        int len = 0;
        while (u < n || v < m) {
          if (v >= m || (u < n && arr[i][u] < arr[j][v])) {
            if (flag != 0) {
              flag = 0;
              ++len;
            }
            ++u;
          } else {
            if (flag != 1) {
              flag = 1;
              ++len;
            }
            ++v;
          }
        }

        res = max(res, len);
      }
    }
    return res;
  }
};
