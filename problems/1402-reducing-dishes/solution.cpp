/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reducing-dishes/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maxSatisfaction(vector<int>& satisfaction) {
    sort(satisfaction.begin(), satisfaction.end(), greater<int>());

    int sum = 0;
    int total = 0;
    int answer = 0;
    for (const int s : satisfaction) {
      sum += s;
      total += sum;
      answer = max(answer, total);
    }
    return answer;
  }
};
