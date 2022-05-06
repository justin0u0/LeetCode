/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
 * Runtime: 24ms
 */

class Solution {
public:
  string removeDuplicates(string s, int k) {
    stack<pair<char, int>> stk;
    stk.push({'!', 0});
    for (const char& c : s) {
      pair<char, int>& p = stk.top();
      if (p.first == c) {
        if (p.second == k - 1) {
          stk.pop();
        } else {
          ++p.second;
        }
      } else {
        stk.push({c, 1});
      }
    }

    string answer = "";
    while (!stk.empty()) {
      answer.append(stk.top().second, stk.top().first);
      stk.pop();
    }
    reverse(answer.begin(), answer.end());

    return answer;
  }
};
