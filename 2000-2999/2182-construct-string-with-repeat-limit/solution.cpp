/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/construct-string-with-repeat-limit/
 * Runtime: 12ms (92.15%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  string repeatLimitedString(const string& s, int repeatLimit) {
    int cnt[128] = {0};
    for (char c : s) {
      ++cnt[c];
    }

    string res = "";
    for (int i = 'z'; i >= 'a'; --i) {
      while (cnt[i] != 0) {
        int repeat = min(repeatLimit, cnt[i]);
        res += string(repeat, i);
        cnt[i] -= repeat;

        if (cnt[i] != 0) {
          bool ok = false;
          for (int j = i - 1; j >= 'a'; --j) {
            if (cnt[j] != 0) {
              res += (char)j;
              --cnt[j];
              ok = true;
              break;
            }
          }
          if (!ok) {
            return res;
          }
        }
      }
    }
    return res;
  }
};
