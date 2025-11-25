/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/smallest-integer-divisible-by-k/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int smallestRepunitDivByK(int k) {
    vector<bool> seen(k, false);

    int num = 0;
    for (int i = 0; i < k; ++i) {
      num = (num * 10 + 1) % k;
      if (num == 0) {
        return i + 1;
      }
      if (seen[num]) {
        break;
      }
      seen[num] = true;
    }
    return -1;
  }
};
