/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/build-an-array-with-stack-operations/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<string> buildArray(vector<int>& target, int n) {
    vector<string> answer;
    answer.reserve(n);
    auto it = target.begin();
    for (int i = 1; i <= n && it != target.end(); ++i) {
      answer.emplace_back("Push");
      if ((*it) != i) {
        answer.emplace_back("Pop");
      } else {
        ++it;
      }
    }
    return answer;
  }
};
