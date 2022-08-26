/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reordered-power-of-2/
 * Runtime: 39ms
 */

class Solution {
public:
  bool reorderedPowerOf2(int n) {
    vector<int> digits;
    while (n > 0) {
      digits.emplace_back(n % 10);
      n /= 10;
    }

    sort(digits.begin(), digits.end());
    do {
      if (digits.front() == 0) {
        continue;
      }
      int x = 0;
      for (const int d : digits) {
        x = x * 10 + d;
      }
      if ((x & (x - 1)) == 0) {
        return true;
      }
    } while (next_permutation(digits.begin(), digits.end()));

    return false;
  }
};
