/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-highest-altitude/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int largestAltitude(vector<int>& gain) {
    int alt = 0;
    int answer = 0;
    for (const int g : gain) {
      alt += g;
      answer = max(answer, alt);
    }
    return answer;
  }
};
