/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/
 * Runtime: 55sms (95.44%)
 */

class Solution {
private:
  int pa[100010];

  int find(int x) {
    if (pa[x] == x) {
      return x;
    }
    return (pa[x] = find(pa[x]));
  }
public:
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
    for (int i = 0; i < queries.size(); ++i) {
      queries[i].emplace_back(i);
    }

    sort(queries.begin(), queries.end(),
      [](const vector<int>& lhs, const vector<int>& rhs) -> bool {
        return lhs[2] < rhs[2];
      });
    sort(edgeList.begin(), edgeList.end(),
      [](const vector<int>& lhs, const vector<int>& rhs) -> bool {
        return lhs[2] < rhs[2];
      });
    for (int i = 0; i < n; ++i) {
      pa[i] = i;
    }

    vector<bool> answer(queries.size(), false);
    auto it = edgeList.begin();
    for (const vector<int>& q : queries) {
      for (; it != edgeList.end() && it->at(2) < q[2]; ++it) {
        int fx = find(it->at(0));
        int fy = find(it->at(1));
        if (fx != fy) {
          pa[fx] = fy;
        }
      }
      if (find(q[0]) == find(q[1])) {
        answer[q[3]] = true;
      }
    }

    return answer;
  }
};
