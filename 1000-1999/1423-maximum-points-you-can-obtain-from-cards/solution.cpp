/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
 * Runtime: 66ms
 */

class Solution {
public:
  int maxScore(vector<int>& cardPoints, int k) {
    int sum = 0;
    int i = 0;
    while (i < k) {
      sum += cardPoints[i];
      ++i;
    }

    int j = (int)cardPoints.size();
    int answer = sum;
    while (i > 0) {
      --i;
      --j;
      sum += cardPoints[j] - cardPoints[i];
      answer = max(answer, sum);
    }

    return answer;
  }
};
