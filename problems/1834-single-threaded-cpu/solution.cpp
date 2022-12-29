/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/single-threaded-cpu/
 * Runtime: 544ms (97.35%)
 */

class Solution {
private:
  struct Task {
    int i;
    int e;
    int p;

    bool operator<(const Task& rhs) const {
      return p > rhs.p || (p == rhs.p && i > rhs.i);
    }
  };
public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    int n = tasks.size();

    vector<Task> vtasks(n);
    for (int i = 0; i < n; ++i) {
      vtasks[i] = Task{i, tasks[i][0], tasks[i][1]};
    }
    sort(vtasks.begin(), vtasks.end(), [](const Task& lhs, const Task& rhs) -> bool {
      return lhs.e < rhs.e;
    });

    vector<int> answer;
    answer.reserve(n);

    int i = 0;
    long long time = 0;
    priority_queue<Task> pq;

    for (int _ = 0; _ < n; ++_) {
      if (pq.empty() && i < n) {
        time = max(time, (long long)vtasks[i].e);
      }

      while (i < n && vtasks[i].e <= time) {
        pq.push(vtasks[i]);
        ++i;
      }

      const Task& t = pq.top();
      time += t.p;
      answer.emplace_back(t.i);
      pq.pop();
    }

    return answer;
  }
};
