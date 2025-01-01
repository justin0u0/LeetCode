/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/fraction-to-recurring-decimal/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string fractionToDecimal(long long n, const int d) {
    if ((n < 0 && d > 0) || (n > 0 && d < 0)) {
      return "-" + fractionToDecimal(-n, d);
    }

    string res = to_string(n / d);
    if (n % d == 0) {
      return res;
    }

    res.push_back('.');
    n %= d;

    unordered_map<int, int> m;
    for (int i = res.size(); n % d != 0; ++i) {
      n *= 10;

      auto it = m.find(n);
      if (it != m.end()) {
        res.insert(it->second, 1, '(');
        res.push_back(')');
        return res;
      }
      m.emplace(n, i);
      res.push_back(n / d + '0');
      n %= d;
    }
    return res;
  }
};
