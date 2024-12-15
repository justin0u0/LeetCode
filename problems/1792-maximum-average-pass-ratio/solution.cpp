/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-average-pass-ratio/
 * Runtime: 423ms (41.03%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  struct Frac {
    int n;
    int d;

    bool operator<(const Frac& rhs) const {
      return (double)(n + 1) / (d + 1) - (double)n / d <
        (double)(rhs.n + 1) / (rhs.d + 1) - (double)rhs.n / rhs.d;
    }
  };
public:
  double maxAverageRatio(const vector<vector<int>>& classes, int extraStudents) {
    priority_queue<Frac> pq;
    for (const auto& c : classes) {
      pq.push({c[0], c[1]});
    }

    while (extraStudents--) {
      auto f = pq.top();
      pq.pop();
      pq.push({f.n + 1, f.d + 1});
    }

    double sum = 0;
    while (!pq.empty()) {
      auto f = pq.top();
      pq.pop();
      sum += (double)f.n / f.d;
    }
    return sum / classes.size();
  }
};
