/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-provinces/
 * Runtime: 20ms (92.44%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  int pa[200];

  int find(int x) {
    if (pa[x] == x) {
      return x;
    }
    return (pa[x] = find(pa[x]));
  }
public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    for (int i = 0; i < n; ++i) {
      pa[i] = i;
    }

    int answer = n;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (isConnected[i][j]) {
          int fi = find(i);
          int fj = find(j);
          if (fi != fj) {
            --answer;
            pa[fi] = fj;
          }
        }
      }
    }

    return answer;
  }
};

