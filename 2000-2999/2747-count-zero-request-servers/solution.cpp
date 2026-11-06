/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-zero-request-servers/
 * Runtime: 149ms (18.18%)
 */

class Solution {
public:
  vector<int> countServers(const int n, vector<vector<int>>& logs, const int x, vector<int>& queries) {
    ranges::sort(logs, {}, [&](const vector<int>& log) {
      return log[1];
    });

    const auto m = queries.size();
    vector<int> indices(m);
    ranges::iota(indices, 0);
    ranges::sort(views::zip(queries, indices));

    int i = 0;
    int j = 0;
    vector<int> seen(n, 0);
    int cnt = 0;

    vector<int> res(m);
    for (const auto& [query, index] : views::zip(queries, indices)) {
      while (i < logs.size() && logs[i][1] <= query) {
        if (++seen[logs[i][0] - 1] == 1) {
          ++cnt;
        }
        ++i;
      }
      while (j < logs.size() && logs[j][1] < query - x) {
        if (--seen[logs[j][0] - 1] == 0) {
          --cnt;
        }
        ++j;
      }
      res[index] = n - cnt;
    }
    return res;
  }
};
