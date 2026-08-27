/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string lexGreaterPermutation(const string& s, const string& target) {
    const auto n = s.length();

    int cnt[128] = {0};
    for (const char c : s) {
      ++cnt[c];
    }

    string res(n, '\0');
    auto dfs = [&](this auto&& self, int i, bool same) {
      if (i == n) {
        return !same || res.back() > target.back();
      }

      int j = 'a';
      if (same) {
        j = target[i];
      }

      for (; j <= 'z'; ++j) {
        if (cnt[j] > 0) {
          --cnt[j];
          res[i] = j;
          if (self(i + 1, same && j == target[i])) {
            return true;
          }
          ++cnt[j];
        }
      }
      return false;
    };
    if (dfs(0, true)) {
      return res;
    }
    return "";
  }
};
