/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sequential-digits/
 * Runtime: 0ms
 */

class Solution {
public:
  vector<int> sequentialDigits(int low, int high) {
    int base = 0;
    int diff = 0;

    vector<int> answer;
    for (int i = 1; i < 10; ++i) {
      base = base * 10 + i;
      diff = diff * 10 + 1;

      int sum = base;
      for (int j = 0; j < 10 - i; ++j) {
        if (sum >= low && sum <= high) {
          answer.emplace_back(sum);
        }
        sum += diff;
      }
    }

    return answer;
  }
};
