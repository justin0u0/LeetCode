/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/counting-bits/
 * Runtime: 3ms
 */

class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> answer{0};

    int j;
    for (int i = 1; i <= n; ++i) {
      if ((i & (i - 1)) == 0) {
        j = 0;
      }

      answer.emplace_back(answer[j++] + 1);
    }

    return answer;
  }
};

