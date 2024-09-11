/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-closest-palindrome/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  inline long long toLong(const string& s) {
    long long x = 0;
    for (char c : s) {
      x = x * 10 + c - '0';
    }
    return x;
  }
public:
  string nearestPalindromic(string& n) {
    int digits = n.length();
    long long x = toLong(n);

    long long p = INT_MAX;
    long long diff = INT_MAX;

    function<void(string&)> update = [&](const string& s) {
      long long y = toLong(s);
      long long d = abs(x - y);
      if (d != 0 && d < diff) {
        diff = d;
        p = y;
      } else if (d == diff && p > y) {
        p = y;
      }
    };

    if (digits != 1) {
      string s(digits - 1, '9');
      update(s);
    }
    if (digits != 18) {
      string s(digits + 1, '0');
      s[0] = '1';
      s.back() = '1';
      update(s);
    }

    {
      string s = n;
      for (int i = digits / 2 + 1; i < digits; ++i) {
        s[i] = s[digits - i - 1];
      }
  
      for (int i = 0; i < 10; ++i) {
        s[digits / 2] = i + '0';
        if (!(digits & 1)) {
          s[digits / 2 - 1] = i + '0';
        }
        update(s);
      }
    }

    {
      string s(digits, '9');
      for (int i = 0; i < digits / 2; ++i) {
        if (n[i] != 0) {
          s[i] = n[i] - 1;
          s[digits - i - 1] = n[i] - 1;
          update(s);
        }

        s[i] = n[i];
        s[digits - i - 1] = n[i];
        update(s);
      }
    }

    {
      string s(digits, '0');
      for (int i = 0; i < digits / 2; ++i) {
        if (n[i] != 9) {
          s[i] = n[i] + 1;
          s[digits - i - 1] = n[i] + 1;
          update(s);
        }

        s[i] = n[i];
        s[digits - i - 1] = n[i];
        update(s);
      }
    }

    return to_string(p);
  }
};
