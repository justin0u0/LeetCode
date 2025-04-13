/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-count-of-good-integers/
 * Runtime: 426ms (50.72%)
 */

class Solution {
private:
  long long fact(int f) {
    long long res = 1;
    for (int i = 1; i <= f; ++i) {
      res *= i;
    }
    return res;
  }

  pair<long long, long long> order(long long x, int digits) {
    int cnt[10] = {0};
    for (long long i = x, j = 1; i != 0; i /= 10, ++j) {
      ++cnt[i % 10];
    }

    long long f = fact(digits);
    long long zf = fact(digits - 1);
    long long res = 0;
    for (int i = 0; i < 10; ++i) {
      if (cnt[i] != 0) {
        f /= fact(cnt[i]);
        if (i == 0) {
          zf /= fact(cnt[0] - 1);
        } else {
          zf /= fact(cnt[i]);
        }
      }
      for (int j = 0; j < cnt[i]; ++j) {
        res = res * 10 + i;
      }
    }
    // cout << x << ' ' << res << ' ' << f << ' ' << zf << endl;
    if (cnt[0] != 0) {
      return {res, f - zf};
    }
    return {res, f};
  }
public:
  long long countGoodIntegers(int n, int k) {
    if (n == 1) {
      return 9 / k;
    }

    // n = 2: [1, 10)
    // n = 3: [1, 10)
    // n = 4: [10, 100)
    int l = 1;
    for (int i = 1; i < (n >> 1); ++i) {
      l *= 10;
    }

    unordered_map<long long, long long> us;

    for (int i = l; i < l * 10; ++i) {
      auto s = to_string(i);
      auto r = s;
      reverse(r.begin(), r.end());

      if (n & 1) {
        for (char j = '0'; j <= '9'; ++j) {
          long long pal = stol(s + j + r);
          if (pal % k == 0) {
            us.emplace(order(pal, n));
          }
        }
      } else {
        long long pal = stol(s + r);
        if (pal % k == 0) {
          us.emplace(order(pal, n));
        }
      }
    }

    long long count = 0;
    for (auto [_, v] : us) {
      count += v;
    }
    return count;
  }
};
