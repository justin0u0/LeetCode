/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/
 * Runtime: 156ms (39.24%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  class TopologicalSort {
  private:
    vector<int> items;                // items stores all items
    unordered_map<int, int> m;        // m maps item with its index in the `items` array
    vector<unordered_set<int>> deps;  // deps[i] is the dependencies of item i

    vector<bool> used;
    vector<bool> inqueue;
    vector<int> sorted;

    bool dfs(int u) {
      used[u] = true;
      inqueue[u] = true;
      for (const int v : deps[u]) {
        if (inqueue[v]) {
          return false;
        }
        if (!used[v] && !dfs(v)) {
          return false;
        }
      }
      sorted.emplace_back(u);
      inqueue[u] = false;
      return true;
    }
  public:
    void addItem(int x) {
      m.emplace(x, items.size());
      items.emplace_back(x);
      deps.resize(items.size());
    }

    void addDependency(int x, int d) {
      deps[m.at(x)].emplace(m.at(d));
    }

    pair<bool, vector<int>&> sort() {
      int n = items.size();
      used.resize(n, false);
      inqueue.resize(n, false);
      sorted.reserve(n);
      for (int i = 0; i < n; ++i) {
        if (!used[i] && !dfs(i)) {
          return {false, sorted};
        }
      }
      for (int& num : sorted) {
        num = items[num];
      }
      return {true, sorted};
    }
  };
public:
  vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    vector<TopologicalSort> groups(m);
    TopologicalSort all;
    for (int i = 0; i < m; ++i) {
      all.addItem(i);
    }
    for (int i = 0; i < n; ++i) {
      const int g = group[i];
      if (g != -1) {
        groups[g].addItem(i);
      } else {
        all.addItem(m + i);
      }
    }
    for (int i = 0; i < n; ++i) {
      const int g = group[i];
      for (const int d : beforeItems[i]) {
        const int gd = group[d];
        if (g != -1 && gd == g) {
          groups[g].addDependency(i, d);
        }
        if (g == -1) {
          if (gd == -1) {
            all.addDependency(m + i, m + d);
          } else {
            all.addDependency(m + i, gd);
          }
        } else {
          if (gd == -1) {
            all.addDependency(g, m + d);
          } else if (g != gd) {
            all.addDependency(g, gd);
          }
        }
      }
    }

    auto [ok, allSorted] = all.sort();
    if (!ok) {
      return {};
    }
    vector<int> answer;
    answer.reserve(n);
    for (const int g : allSorted) {
      if (g >= m) {
        answer.emplace_back(g - m);
        continue;
      }

      auto [ok, sorted] = groups[g].sort();
      if (!ok) {
        return {};
      }
      for (const int i : sorted) {
        answer.emplace_back(i);
      }
    }
    return answer;
  }
};
