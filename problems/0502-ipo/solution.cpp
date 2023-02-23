/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/ipo/
 * Runtime: 218ms (87.58%)
 */

class Solution {
public:
  int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n = profits.size();
    vector<pair<int, int>> projects(n);
    for (int i = 0; i < n; ++i) {
      projects[i] = {capital[i], profits[i]};
    }
    sort(projects.begin(), projects.end());

    auto p = projects.begin();
    priority_queue<int> pq;
    for (int i = 0; i < k; ++i) {
      while (p != projects.end() && p->first <= w) {
        pq.push(p->second);
        ++p;
      }
      if (pq.empty()) {
        break;
      }

      w += pq.top();
      pq.pop();
    }

    return w;
  }
};
