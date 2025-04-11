/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-symmetric-integers/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  static vector<int> syms;
public:
  int countSymmetricIntegers(int low, int high) {
    return lower_bound(syms.begin(), syms.end(), high + 1) - lower_bound(syms.begin(), syms.end(), low);
  }
};

vector<int> Solution::syms = []() {
  vector<int> v{11, 22, 33, 44, 55, 66, 77, 88, 99};
  for (int i = 10; i < 100; ++i) {
    int sum = 0;
    for (int j = i; j != 0; j /= 10) {
      sum += j % 10;
    }

    for (int j = max(sum - 9, 0); j <= min(sum, 9); ++j) {
      v.emplace_back(i * 100 + j * 10 + (sum - j));
    }
  }

  return v;
}();
