/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  char kthCharacter(const long long k, const vector<int>& operations) {
    if (k == 1) {
      return 'a';
    }

    long long x = 1;
    int ops = 0;
    while ((x << 1) < k) {
      x <<= 1;
      ++ops;
    }

    char c = kthCharacter(k - x, operations);
    if (operations[ops] == 0) {
      return c;
    }
    if (c == 'z') {
      return 'a';
    }
    return c + 1;
  }
};
