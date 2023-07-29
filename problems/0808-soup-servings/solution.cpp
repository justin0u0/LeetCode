/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/soup-servings/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  double dp[200][200];

  double solve(int a, int b) {
    if (a <= 0 && b <= 0) {
      return 0.5;
    }
    if (a <= 0) {
      return 1;
    }
    if (b <= 0) {
      return 0;
    }

    double& d = dp[a][b];
    if (d != 0) {
      return d;
    }

    d = 0.25 * solve(a - 4, b) +
      0.25 * solve(a - 3, b - 1) +
      0.25 * solve(a - 2, b - 2) +
      0.25 * solve(a - 1, b - 3);
    return d;
  }
public:
  double soupServings(int n) {
    if (n > 4800) {
      return 1;
    }

    return solve((n + 24) / 25, (n + 24) / 25);
  }
};
