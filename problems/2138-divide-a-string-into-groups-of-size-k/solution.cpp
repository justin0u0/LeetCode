/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<string> divideString(const string& s, const int k, const char fill) {
    const int n = s.length();
    vector<string> res;
    for (int i = 0; i < n; i += k) {
      res.emplace_back(s.substr(i, k));
    }
    if (n % k != 0) {
      res.back() += string(k - n % k, fill);
    }
    return res;
  }
};
