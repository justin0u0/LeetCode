/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/
 * Runtime: 1552ms (11.81%)
 */

class Solution {
public:
  int minJumps(vector<int>& nums) {
    const int n = nums.size();

    if (n < 2) {
      return 0;
    }

    vector<bool> primes(n, true);
    unordered_map<int, vector<int>> loc;
    for (const auto [index, num] : nums | views::enumerate) {
      for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
          primes[index] = false;
          break;
        }
      }
      if (num > 1 && primes[index]) {
        loc[num].emplace_back(index);
      }
    }

    vector<vector<int>> edges(n);
    for (const auto [v, num] : nums | views::enumerate) {
      for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
          for (int u : loc[i]) {
            edges[u].emplace_back(v);
          }
          for (int u : loc[num / i]) {
            edges[u].emplace_back(v);
          }
        }
      }
    }

    queue<int> q;
    q.push(0);

    vector<bool> vis(n, false);
    vis[0] = true;

    for (int dist = 0; ; ++dist) {
      auto size = q.size();
      while (size--) {
        const int u = q.front();
        q.pop();

        if (u == n - 1) {
          return dist;
        }

        if (u > 0 && !vis[u - 1]) {
          q.push(u - 1);
          vis[u - 1] = true;
        }
        if (u + 1 < n && !vis[u + 1]) {
          q.push(u + 1);
          vis[u + 1] = true;
        }
        for (int v : edges[u]) {
          if (!vis[v]) {
            q.push(v);
            vis[v] = true;
          }
        }
        for (int v : loc[nums[u]]) {
          if (!vis[v]) {
            q.push(v);
            vis[v] = true;
          }
        }
        loc.erase(nums[u]);
      }
    }

    return 0;
  }
};
