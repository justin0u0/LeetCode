/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/largest-substring-between-two-equal-characters/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maxLengthBetweenEqualCharacters(const string& s) {
    vector<int> first(128, -1);
    int answer = -1;
    for (int i = 0; i < s.length(); ++i) {
      if (first[s[i]] != -1) {
        answer = max(answer, i - first[s[i]] - 1);
      } else {
        first[s[i]] = i;
      }
    }
    return answer;
  }
};
