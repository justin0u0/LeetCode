/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/counting-bits/
 * Runtime: 10ms
 */

class Solution {
public:
  vector<int> countBits(int n) {
    ++n;
    vector<int> answer{0, 1, 1, 2};

    for (int l = 1; l * 4 < n; ++l) {
      int v = answer[l];
      answer.emplace_back(v);
      answer.emplace_back(v + 1);
      answer.emplace_back(v + 1);
      answer.emplace_back(v + 2);
    }

    while (answer.size() > n) {
      answer.pop_back();
    }

    return answer;
  }
};

// 0
// 1
// 1 2
// 1 2 2 3 -- 1
// 1 2 2 3 2 3 3 4 -- 1, 2
// 1 2 2 3 2 3 3 4 2 3 3 4 3 4 4 5
// 1 2 2 3 2 3 3 4 2 3 3 4 3 4 4 5 2 3 3 4 3 4 4 5 3 4 4 5 4 5 5 6
// 1 2 2 3 2 3 3 4 2 3 3 4 3 4 4 5 2 3 3 4 3 4 4 5 3 4 4 5 4 5 5 6 2 3 3 4 3 4 4 5 3 4 4 5 4 5 5 6 3 4 4 5 4 5 5 6 4 5 5 6 5 6 6 7 -- 1,2,2,3,2,3,3,4
// 1 2 2 3 2 3 3 4 2 3 3 4 3 4 4 5 2 3 3 4 3 4 4 5 3 4 4 5 4 5 5 6 2 3 3 4 3 4 4 5 3 4 4 5 4 5 5 6 3 4 4 5 4 5 5 6 4 5 5 6 5 6 6 7 2 3 3 4 3 4 4 5 3 -- 

