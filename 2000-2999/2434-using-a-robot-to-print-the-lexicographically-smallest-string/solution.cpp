/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/
 * Runtime: 124ms (20.30%)
 */

class Solution {
public:
  string robotWithString(const string& s) {
    // Push characters into stack, character can only be popped if there is no
    // smaller character left.
    const int n = s.length();

    vector<int> wait(n, 0);
    vector<int> last(26, -1);
    for (int i = n - 1; i >= 0; --i) {
      const int c = s[i] - 'a';
      last[c] = max(last[c], i);
      for (int j = 0; j < c; ++j) {
        wait[i] = max(wait[i], last[j]);
      }
    }

    stack<int> stk;
    string res = "";
    res.reserve(n);
    for (int i = 0; i < n; ++i) {
      stk.push(i);
      while (!stk.empty() && wait[stk.top()] <= i) {
        res += s[stk.top()];
        stk.pop();
      }
    }
    return res;
  }
};
