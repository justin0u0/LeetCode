/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/process-tasks-using-servers/
 * Runtime: 140ms (86.80%)
 */

class Solution {
public:
  vector<int> assignTasks(const vector<int>& servers, const vector<int>& tasks) {
    using PII = pair<int, int>;
    using PLI = pair<long long, int>;
    priority_queue<PII, vector<PII>, greater<PII>> free; // weight, task
    priority_queue<PLI, vector<PLI>, greater<PLI>> busy; // time, task

    for (int i = 0; i < servers.size(); ++i) {
      free.push({servers[i], i});
    }
    
    const int m = tasks.size();
    vector<int> assignee(m);
    long long t = 0;
    for (int i = 0; i < m; ++i) {
      t = max(t, (long long)i);
      if (free.empty()) {
        t = max(t, busy.top().first);
      }
      while (!busy.empty() && busy.top().first <= t) {
        const int j = busy.top().second;
        busy.pop();
        free.push({servers[j], j});
      }

      const int j = free.top().second;
      free.pop();
      busy.push({t + tasks[i], j});
      assignee[i] = j;
    }
    return assignee;
  }
};
