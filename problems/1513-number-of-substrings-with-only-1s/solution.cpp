/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-substrings-with-only-1s/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int numSub(string& s) {
    s += '0';

    int sum = 0;
    int cnt = 0;
    for (char c : s) {
      if (c == '1') {
        ++cnt;
      } else {
        sum += ((long long)cnt * (cnt + 1) / 2) % mod;
        sum %= mod;
        cnt = 0;
      }
    }
    return sum;
  }
};

/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-substrings-with-only-1s/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int numSub(string& s) {
    s += '0';

    int sum = 0;
    int cnt = 0;
    for (char c : s) {
      if (c == '1') {
        ++cnt;
      } else {
        sum += ((long long)cnt * (cnt + 1) / 2) % mod;
        sum %= mod;
        cnt = 0;
      }
    }
    return sum;
  }
};
