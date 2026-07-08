/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/
 * Runtime: 52ms (40.93%)
 */

class Solution {
private:
  inline static constexpr int mod = 1e9 + 7;

  inline long long pow(long long a, int p) {
    long long res = 1;
    while (p > 0) {
      if (p & 1) {
        res = res * a % mod;
      }
      a = a * a % mod;
      p >>= 1;
    }
    return res;
  }
public:
  vector<int> sumAndMultiply(const string& s, const vector<vector<int>>& queries) {
    const int n = s.length();

    vector<int> sum(n + 1, 0);
    vector<long long> mul(n + 1);
    mul[n] = 0;
    vector<long long> base(n + 1);
    base[n] = 1;

    for (int i = n - 1; i >= 0; --i) {
      sum[i] = sum[i + 1] + s[i] - '0';
      base[i] = base[i + 1];
      if (s[i] == '0') {
        mul[i] = mul[i + 1];
      } else {
        mul[i] = (mul[i + 1] + base[i] * (s[i] - '0')) % mod;
        base[i] = base[i] * 10 % mod;
      }
    }

    vector<int> res;
    res.reserve(queries.size());
    for (const auto& query : queries) {
      const auto y = sum[query[0]] - sum[query[1] + 1];
      // a/b%p=a*b^p-2%p
      // const auto x = (mul[query[0]] - mul[query[1] + 1] + mod) / base[query[1] + 1];
      const auto x = (mul[query[0]] - mul[query[1] + 1] + mod) *
        pow(base[query[1] + 1], mod - 2) % mod;
      res.emplace_back(x * y % mod);
    }
    return res;
  }
};
