/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/multiply-strings/
 * Runtime: 2ms (79.30%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  string multiply(string& num1, string& num2) {
    const int n = num1.size();
    const int m = num2.size();
    vector<int> mul(n + m, 0);

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        mul[i + j] += (num1[i] - '0') * (num2[j] - '0');
      }
    }

    int carry = 0;
    for (int i = 0; i < n + m; ++i) {
      mul[i] += carry;
      carry = mul[i] / 10;
      mul[i] %= 10;
    }

    int high = n + m - 1;
    while (high != 0 && mul[high] == 0) {
      --high;
    }

    string s;
    s.reserve(high + 1);
    for (int i = high; i >= 0; --i) {
      s += mul[i] + '0';
    }
    return s;
  }
};
