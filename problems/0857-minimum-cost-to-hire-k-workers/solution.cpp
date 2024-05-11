/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
 * Runtime: 12ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  struct Worker {
    int q;
    int w;

    bool operator<(const Worker& rhs) const {
      return w * rhs.q < q * rhs.w;
    }
  };
public:
  double mincostToHireWorkers(const vector<int>& quality, const vector<int>& wage, int k) {
    // Assume that we select a group of workers with the largest W/Q=X, then
    // all workers in that group have w = q * X. Choosing k workers in the
    // group with minimum cost is same as choosing k workers with the minimum
    // quality as X is the same.
    //
    // We add worker to the group order by W/Q ascendingly, which means that we
    // always know the largest Q/W in the group is the newly added worker. Then
    // we can easily maintain the Kth smallest quality of workers in that group
    // using a priority queue.

    const int n = quality.size();
    vector<Worker> workers(n);
    for (int i = 0; i < n; ++i) {
      workers[i] = {quality[i], wage[i]};
    }
    sort(workers.begin(), workers.end());

    priority_queue<int> qualities;
    int sum = 0;
    for (int i = 0; i < k; ++i) {
      const Worker& w = workers[i];
      qualities.push(w.q);
      sum += w.q;
    }

    double answer = sum * ((double)workers[k - 1].w / workers[k - 1].q);
    for (int i = k; i < n; ++i) {
      const Worker& w = workers[i];
      sum += w.q;
      qualities.push(w.q);
      sum -= qualities.top();
      qualities.pop();
      answer = min(answer, sum * ((double)w.w / w.q));
    }
    return answer;
  }
};
