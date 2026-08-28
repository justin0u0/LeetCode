/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string lexPalindromicPermutation(const string& s, const string& target) {
    const int n = s.length();
    const int m = (n - 1) / 2;

    if (n == 1) {
      return s[0] > target[0] ? s : "";
    }

    int cnt[128] = {0};
    for (const char c : s) {
      ++cnt[c];
    }

    int odd = 0;
    for (int i = 'a'; i <= 'z'; ++i) {
      if (cnt[i] & 1) {
        ++odd;
      }
    }
    if (odd > 1 || (odd > 0 && !(n & 1))) {
      return "";
    }

    string res(n, '\0');

    auto dfs = [&](this auto&& self, int i, bool same) {
      if (i > m) {
        if (!same) {
          return true;
        }
        for (int j = i; j < n; ++j) {
          if (res[j] < target[j]) {
            return false;
          }
          if (res[j] > target[j]) {
            return true;
          }
        }
        return false;
      }

      int j = 'a';
      if (same) {
        j = target[i];
      }
      for (; j <= 'z'; ++j) {
        if (cnt[j] > 1) {
          cnt[j] -= 2;
        } else if ((n & 1) && i == m && cnt[j] > 0) {
          --cnt[j];
        } else {
          continue;
        }

        res[i] = j;
        res[n - i - 1] = j;

        if (self(i + 1, same && j == target[i])) {
          return true;
        }

        if ((n & 1) && i == m) {
          ++cnt[j];
        } else {
          cnt[j] += 2;
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
