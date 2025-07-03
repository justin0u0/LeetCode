/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  char kthCharacter(int k) {
    if (k == 1) {
      return 'a';
    }

    int p = 1;
    while ((p << 1) < k) {
      p <<= 1;
    }
    
    char c = kthCharacter(k - p);
    if (c == 'z') {
      return 'a';
    }
    return c + 1;
  }
};
