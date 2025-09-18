/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/design-task-manager/
 * Runtime: 197ms (90.31%)
 */

class TaskManager {
private:
  struct Task {
    int id;
    int uid;
    int prio;

    bool operator<(const Task& rhs) const {
      return prio < rhs.prio || (prio == rhs.prio && id < rhs.id);
    }
  };

  priority_queue<Task> pq;
  unordered_map<int, pair<int, int>> m;
public:
  TaskManager(vector<vector<int>>& tasks) {
    for (const auto& t : tasks) {
      add(t[0], t[1], t[2]);
    }
  }

  void add(int userId, int taskId, int priority) {
    pq.push({taskId, userId, priority});
    m.emplace(taskId, pair{userId, priority});
  }

  void edit(int taskId, int newPriority) {
    auto it = m.find(taskId);
    pq.push({taskId, it->second.first, newPriority});
    it->second.second = newPriority;
  }

  void rmv(int taskId) {
    m.erase(taskId);
  }

  int execTop() {
    while (!pq.empty()) {
      auto t = pq.top();
      pq.pop();
      auto it = m.find(t.id);
      if (it != m.end() && it->second.first == t.uid && it->second.second == t.prio) {
        rmv(t.id);
        return t.uid;
      }
    }
    return -1;
  }
};
