/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string smallestSubsequence(const string& s) {
    vector<int> last(128, 0);
    for (const auto [i, c] : s | views::enumerate) {
      last[c] = i;
    }

    vector<bool> used(128, false);
    stack<char> stk;
    for (const auto [i, c] : s | views::enumerate) {
      if (used[c]) {
        continue;
      }
      while (!stk.empty() && stk.top() > c && last[stk.top()] > i) {
        used[stk.top()] = false;
        stk.pop();
      }
      used[c] = true;
      stk.push(c);
    }
    
    string res;
    while (!stk.empty()) {
      res.push_back(stk.top());
      stk.pop();
    }
    ranges::reverse(res);
    return res;
  }
};
