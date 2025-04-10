/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-the-number-of-powerful-integers/
 * Runtime: 1ms (61.40%)
 */

class Solution {
  using ll = long long;
private:
  pair<ll, int> baseAndDigits(ll x) {
    long long base = 1;
    int digits = 1;
    while (base * 10 < x) {
      base *= 10;
      ++digits;
    }
    return {base, digits};
  }
public:
  ll numberOfPowerfulInt(const ll start, const ll finish, const int limit, const string& s) {
    ll suffix = 0;
    for (char c : s) {
      suffix = suffix * 10 + c - '0';
    }

    unordered_map<ll, ll> dp;

    // solve(x): number of powerful integers not greater than x
    //
    // numberOfPowerFulInt(start, finish) = solve(finish) - solve(start)
    //
    // Assume that there is `d` digits and `b` is the largest power of 10 not greater
    // then `x`, then solve(x) = 
    //    min(y, limit + 1) * solve(b - 1) => x=4123 -> count 0xxx, 1xxx, 2xxx, 3xxx
    //    + solve(x - x / b * b)           => x=4123 -> count 4xxx if available
    function<ll(ll, ll, int)> solve = [&](const ll x, const ll base, const int digits) {
      if (digits <= s.length()) {
        return (ll)(x >= suffix);
      }

      auto it = dp.find(x);
      if (dp.find(x) != dp.end()) {
        return it->second;
      }

      ll y = x / base;
      ll res = min(y, (ll)limit + 1) * solve(base - 1, base / 10, digits - 1);
      if (y <= limit) {
        res += solve(x - x / base * base, base / 10, digits - 1);
      }
      return dp[x] = res;
    };

    auto [b1, d1] = baseAndDigits(finish);
    auto [b2, d2] = baseAndDigits(start - 1);

    return solve(finish, b1, d1) - solve(start - 1, b2, d2);
  }
};
