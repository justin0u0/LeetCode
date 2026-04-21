/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/
 * Runtime: 102ms (92.15%)
 */

class Solution {
private:
  int pa[100001];

  int find(int x) {
    if (pa[x] == x) {
      return x;
    }
    return pa[x] = find(pa[x]);
  }
public:
  int minimumHammingDistance(const vector<int>& source, const vector<int>& target, const vector<vector<int>>& allowedSwaps) {
    const int n = source.size();
    for (int i = 0; i < n; ++i) {
      pa[i] = i;
    }

    for (const auto& swp : allowedSwaps) {
      int x = find(swp[0]);
      int y = find(swp[1]);
      if (x > y) {
        swap(x, y);
      }
      pa[y] = x;
    }

    vector<unordered_map<int, int>> groups(n);
    for (int i = 0; i < n; ++i) {
      ++groups[find(i)][source[i]];
    }

    int dist = 0;
    for (int i = 0; i < n; ++i) {
      if (--groups[find(i)][target[i]] < 0) {
        ++dist;
      }
    }
    return dist;
  }
};
