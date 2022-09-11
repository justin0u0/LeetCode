/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-performance-of-a-team/
 * Runtime: 86ms
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
      v[i] = pair{efficiency[i], speed[i]};
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());

    int minEfficiency = 1;
    long long sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    long long answer = 0;
    for (const pair<int, int>& p : v) {
      minEfficiency = p.first;
      sum += p.second;
      pq.push(p.second);
      if (pq.size() > k) {
        sum -= pq.top();
        pq.pop();
      }

      answer = max(answer, sum * minEfficiency);
    }

    return answer % mod;
  }
};
