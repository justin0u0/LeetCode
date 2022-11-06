/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/orderly-queue/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string orderlyQueue(string& s, int k) {
    if (k > 1) {
      sort(s.begin(), s.end());
      return s;
    }

    string answer = s;
    for (int i = 1; i < s.size(); ++i) {
      rotate(s.begin(), s.begin() + 1, s.end());
      answer = min(answer, s);
    }

    return answer;
  }
};
