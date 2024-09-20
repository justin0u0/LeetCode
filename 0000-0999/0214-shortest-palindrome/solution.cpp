/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/shortest-palindrome/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  string shortestPalindrome(const string& s) {
    // To find the shortest palindrome by adding characters in front, it is
    // equivelant to finding the longest palindrome and add revered, missing
    // suffix to the prefix.
  
    // For example s = "aacecaaa"
    //
    // All prefix
    // a
    // aa
    // aac
    // aace
    // aacec
    // aaceca
    // aacecaa  <- longest palindrome => add missing suffix "a" to the prefix
    // aacecaaa
    const int n = s.length() * 2 + 1;
    string ss(n, '.');
    for (int i = 1; i < n; i += 2) {
      ss[i] = s[i >> 1];
    }

    // `p[i]` is the longest palindrome starting with ss[i] as the center.
    // `[l, r]` is the rightmost range of all known p[i]
    //
    // To calculate `p[i]`, there are 2 cases:
    // 1. If i > r, then we don't have any information about `p[i]`, we can
    //    start expanding from point `i`.
    // 2. Else (i <= r), then we can find the mirroring point of `i` in the
    //    range `[l, r]`, which is `j = l + (r - i)`.
    //    a. If i + p[j] < r, which also implies that j - p[j] > l, then we
    //        make sure that p[i] = p[j] because we can mirror [ss[j]-p[j],
    //        ss[j]+p[j]] to [ss[i]-p[j], ss[i]+p[j]] as they are all in range
    //        `[l, r]`.
    //    b. Else if i + p[j] == r, then it is possible that we can expand to a
    //        further range. We can set `p[i] = p[j]` then expand the range.
    //    c. Else (i + p[j] > r), then the out of range information cannot be
    //        be used. So we can at most set `p[i] = r - i` so the range using
    //        `i` as the center is `i + r - i = r`, then we follow step b.

    // Make sure the while loop always stop
    ss = '^' + ss + '$';

    vector<int> p(n + 2, 0);
    int l = 1;
    int r = 1;

    // Don't calculate the first character `^` and the last character `$`.
    for (int i = 1; i <= n; ++i) {
      // `max(0, ...)` for the `i > r` case.
      p[i] = max(0, min(p[l + r - i], r - i));
      while (ss[i - p[i]] == ss[i + p[i]]) {
        ++p[i];
      }
      if (i + p[i] > r) {
        l = i - p[i];
        r = i + p[i];
      }
    }

    /*
    for (int i = 1; i <= n; ++i) {
      cout << i%10 << ' ';
    } cout << endl;
    for (int i = 1; i <= n; ++i) {
      cout << ss[i] << ' ';
    } cout << endl;
    for (int i = 1; i <= n; ++i) {
      cout << p[i] << ' ';
    } cout << endl;
    */

    for (int i = n; i >= 1; --i) {
      if (p[i] == i) {
        string res = "";
        for (int j = n - 1; j >= i + p[i]; j -= 2) {
          res += ss[j];
        }
        return res + s;
      }
    }

    return "";
  }
};
