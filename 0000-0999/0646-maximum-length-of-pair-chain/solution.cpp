/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-length-of-pair-chain/
 * Runtime: 41ms (99.18%)
 */

class Solution {
public:
  int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), [](const auto& lhs, const auto& rhs) {
      return (lhs[0] < rhs[0]) || (lhs[0] == rhs[0] && lhs[1] < rhs[1]);
    });

    int last = -1001;
    int answer = 0;
    for (const auto& p : pairs) {
      if (last < p[0]) {
        last = p[1];
        ++answer;
      } else {
        last = min(last, p[1]);
      }
    }
    return answer;
  }
};
