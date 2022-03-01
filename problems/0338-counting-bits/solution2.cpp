/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/counting-bits/
 * Runtime: 4ms
 */

class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> answer{0};

    for (int i = 1; i <= n; (i <<= 1)) {
      int m = min(i + i, n + 1);
      for (int j = i; j < m; ++j) {
        answer.emplace_back(answer[j - i] + 1);
      }
    }

    return answer;
  }
};

