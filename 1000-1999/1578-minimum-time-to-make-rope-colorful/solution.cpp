/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
 * Runtime: 179ms (85.69%)
 */

class Solution {
public:
  int minCost(const string& colors, const vector<int>& neededTime) {
    int answer = 0;
    int prevColor = 0;
    int maxCost = 0;
    int totalCost = 0;
    for (int i = 0; i < colors.size(); ++i) {
      if (colors[i] != prevColor) {
        answer += totalCost - maxCost;
        prevColor = colors[i];
        maxCost = 0;
        totalCost = 0;
      }
      int t = neededTime[i];
      maxCost = max(maxCost, t);
      totalCost += t;
    }
    answer += totalCost - maxCost;

    return answer;
  }
};
