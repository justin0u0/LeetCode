/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/range-product-queries-of-powers/
 * Runtime: 11ms (85.11%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  vector<int> productQueries(int n, vector<vector<int>>& queries) {
    vector<int> powers;
    for (int i = (1 << 30); i > 0; i >>= 1) {
      if (n >= i) {
        n -= i;
        powers.emplace_back(i);
      }
    }
    reverse(powers.begin(), powers.end());

    vector<int> res;
    res.reserve(queries.size());
    for (const auto& q : queries) {
      long long mul = 1;
      for (int i = q[0]; i <= q[1]; ++i) {
        mul = (mul * powers[i]) % mod;
      }
      res.emplace_back(mul);
    }
    return res;
  }
};
