/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
 * Runtime: 27ms
 */

class Solution {
public:
  string minRemoveToMakeValid(string s) {
    int n = (int)s.length();
    stack<int> box;
    vector<bool> removed(n, false);
    
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        box.push(i);
      }
      if (s[i] == ')') {
        if (box.empty()) {
          removed[i] = true;
        } else {
          box.pop();
        }
      }
    }

    while (!box.empty()) {
      removed[box.top()] = true;
      box.pop();
    }

    string answer = "";
    for (int i = 0; i < n; ++i) {
      if (!removed[i]) {
        answer += s[i];
      }
    }

    return answer;
  }
};
