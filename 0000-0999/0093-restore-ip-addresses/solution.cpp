/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/restore-ip-addresses/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  inline bool check(string& s, int l, int r) {
    if (s[l] == '0' && l + 1 != r) {
      return false;
    }
    int x = 0;
    for (int i = l; i < r; ++i) {
      x = x * 10 + s[i] - '0';
    }
    return x >= 0 && x <= 255;
  }
public:
  vector<string> restoreIpAddresses(string& s) {
    vector<string> answer;
    int n = s.size();
    for (int i = 1; i < 4; ++i) {
      if (!check(s, 0, i)) {
        continue;
      }
      for (int j = i + 1; j < min(i + 4, n); ++j) {
        if (!check(s, i, j)) {
          continue;
        }
        for (int k = j + 1; k < min(j + 4, n); ++k) {
          if (!check(s, j, k) || n - k > 3 || !check(s, k, n)) {
            continue;
          }
          answer.emplace_back(
            s.substr(0, i)
            + "." + s.substr(i, j - i)
            + "." + s.substr(j, k - j)
            + "." + s.substr(k, n - k)
          );
        }
      }
    }
    return answer;
  }
};
