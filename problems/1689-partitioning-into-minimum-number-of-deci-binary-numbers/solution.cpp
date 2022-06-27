/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
 * Runtime: 24ms
 */

class Solution {
public:
  int minPartitions(string n) {
    char answer = 0;
    for (const char c : n) {
      answer = max(answer, c);
    }

    return answer - '0';
  }
};
