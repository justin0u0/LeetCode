/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-cost-to-convert-string-i/
 * Runtime: 92ms (99.76%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long minimumCost(const string& source, const string& target, const vector<char>& original, const vector<char>& changed, const vector<int>& cost) {
    int dist[26][26];
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    for (int i = 0; i < 26; ++i) {
      dist[i][i] = 0;
    }

    const int m = cost.size();
    for (int i = 0; i < m; ++i) {
      const int u = original[i] - 'a';
      const int v = changed[i] - 'a';
      dist[u][v] = min(dist[u][v], cost[i]);
    }

    for (int k = 0; k < 26; ++k) {
      for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }

    long long total = 0;
    for (int i = 0; i < source.size(); ++i) {
      const int d = dist[source[i] - 'a'][target[i] - 'a'];
      if (d == 0x3f3f3f3f) {
        return -1;
      }
      total += d;
    }
    return total;
  }
};
