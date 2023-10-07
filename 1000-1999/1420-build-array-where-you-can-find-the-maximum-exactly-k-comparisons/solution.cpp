/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/
 * Runtime: 9ms (90.78%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int numOfArrays(int n, int m, int k) {
    vector<vector<int>> pre(k + 1, vector<int>(m + 1, 0));
    vector<vector<int>> cur(k + 1, vector<int>(m + 1, 0));
    pre[0][0] = 1;
    for (int x = 1; x <= n; ++x) {
      for (int i = 1; i <= k; ++i) {
        int sum = pre[i - 1][0];
        for (int j = 1; j <= m; ++j) {
          cur[i][j] = ((long)pre[i][j] * j + sum) % mod;
          sum = (sum + pre[i - 1][j]) % mod;
        }
      }
      cur[0][0] = 0;
      swap(pre, cur);
    }

    int answer = 0;
    for (int dp : pre[k]) {
      answer = (answer + dp) % mod;
    }
    return answer;
  }
};

// dp(x, i, j): the xth number, search_cost = i, maximum_value = j
//  = sum{dp(x - 1, i - 1, j')} ∀ j' < j
//    + dp(x - 1, i, j) * j
