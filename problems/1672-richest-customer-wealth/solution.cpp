/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/richest-customer-wealth/
 * Runtime: 8ms
 */

class Solution {
public:
  int maximumWealth(vector<vector<int>>& accounts) {
    int answer = 0;
    for (vector<int>& account : accounts) {
      int sum = 0;
      for (int val : account) {
        sum += val;
      }
      answer = max(answer, sum);
    }

    return answer;
  }
};
