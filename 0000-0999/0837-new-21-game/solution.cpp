/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/new-21-game/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  double new21Game(int n, int k, int maxPts) {
    if (k == 0) {
      return 1.0;
    }

    // Let p(i) be the probability of getting i points,
    //  p(i) = (sum{p(j)} / maxPts) where max{0, i-maxPts} <= j <= min{k, i-1}.
    // Why? -> p(j) is the probability of getting j points, if max{0, i-maxPts} <= j <= min{k, i-1},
    //         it can get points randomly from [1, maxPts], so there is (1/maxPts) chance of getting
    //         (i-j) points.
    vector<double> p(n + 1, 0);
    p[0] = 1;

    double answer = 0;
    double sum = 1.0;
    for (int i = 1; i <= n; ++i) {
      int j = i - maxPts - 1;
      if (j >= 0 && j < k) {
        sum -= p[j];
      }

      p[i] = sum / maxPts;
      if (i < k) {
        sum += p[i];
      } else {
        answer += p[i];
      }
    }

    return answer;
  }
};
