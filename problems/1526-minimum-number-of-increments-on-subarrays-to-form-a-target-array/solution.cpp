/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
 * Runtime: 191ms (5.22%)
 */

class Solution {
private:
  int size[100001];
  int pa[100001];

  int find(const int x) {
    if (pa[x] == x) {
      return x;
    }
    return pa[x] = find(pa[x]);
  }

  void merge(const int x, const int y) {
    int fx = find(pa[x]);
    int fy = find(pa[y]);
    if (fx < fy) {
      swap(fx, fy);
    }
    if (fx != fy) {
      pa[fx] = fy;
      size[fy] += size[fx];
    }
  }
public:
  int minNumberOperations(vector<int>& target) {
    priority_queue<pair<int, int>> pq;

    const int n = target.size();
    int mn = INT_MAX;
    for (int i = 0; i < n; ++i) {
      pa[i] = i;
      size[i] = 1;
      if (i > 0 && target[i] == target[i - 1]) {
        merge(i - 1, i);
      } else {
        pq.push({target[i], i});
      }
      mn = min(mn, target[i]);
    }

    int ops = 0;
    while (!pq.empty()) {
      auto [_, x] = pq.top();
      pq.pop();

      int fx = find(x);
      if (fx != x) {
        continue;
      }
      int t = target[x];

      int left = t;
      int right = t;
      if (x > 0) {
        left = min(left, target[x - 1]);
      }
      if (x + size[x] < n) {
        right = min(right, target[x + size[x]]);
      }

      if (left == t && right == t) {
        continue;
      }

      if (right == t || (left != t && left > right)) {
        merge(x - 1, x);
        ops += t - left;
      } else if (left == t || left < right) {
        merge(x, x + size[x]);
        ops += t - right;
        target[x] = right;
        pq.push({right, x});
      } else {
        merge(x - 1, x);
        merge(x, x + size[x]);
        ops += t - left;
      }
    }

    return ops + mn;
  }
};
