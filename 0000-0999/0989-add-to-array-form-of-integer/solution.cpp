/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/add-to-array-form-of-integer/
 * Runtime: 23ms (94.54%)
 */

class Solution {
public:
  vector<int> addToArrayForm(vector<int>& num, int k) {
    for (int i = num.size() - 1; k != 0 && i >= 0; --i) {
      num[i] += k;
      k = num[i] / 10;
      num[i] %= 10;
    }
    while (k != 0) {
      num.insert(num.begin(), k % 10);
      k /= 10;
    }
    return num;
  }
};
