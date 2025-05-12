/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/finding-3-digit-even-numbers/
 * Runtime: 36ms (36.86%)
 */

class Solution {
public:
  vector<int> findEvenNumbers(const vector<int>& digits) {
    bitset<1000> b;

    const int n = digits.size();
    for (int i = 0; i < n; ++i) {
      if (digits[i] == 0) {
        continue;
      }
      for (int j = 0; j < n; ++j) {
        if (i == j || digits[j] & 1) {
          continue;
        }
        for (int k = 0; k < n; ++k) {
          if (k != i && k != j) {
            b.set(digits[i] * 100 + digits[k] * 10 + digits[j]);
          }
        }
      }
    }

    vector<int> res;
    for (int i = 100; i < 1000; ++i) {
      if (b[i]) {
        res.emplace_back(i);
      }
    }
    return res;
  }
};
