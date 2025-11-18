/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/1-bit-and-2-bit-characters/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool isOneBitCharacter(const vector<int>& bits) {
    bool last0 = false;
    for (int i = 0; i < bits.size(); ) {
      if (bits[i] == 1) {
        i += 2;
        last0 = false;
      } else {
        i += 1;
        last0 = true;
      }
    }
    return last0;
  }
};
