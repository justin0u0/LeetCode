/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/validate-stack-sequences/
 * Runtime: 7ms
 */

class Solution {
public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> s;

    vector<int>::iterator it = popped.begin();
    for (const int& val : pushed) {
      s.push(val);

      while (it != popped.end() && !s.empty() && (*it) == s.top()) {
        s.pop();
        it = next(it);
      }
    }

    return (it == popped.end());
  }
};
