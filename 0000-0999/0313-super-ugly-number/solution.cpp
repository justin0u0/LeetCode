/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/super-ugly-number/
 * Runtime: 110ms (50.26%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int nthSuperUglyNumber(const int n, const vector<int>& primes) {
    vector<int> ugly(n);
    ugly[0] = 1;

    // Keep track of the ugly number index to multiply for each prime.
    vector<int> index(primes.size(), 0);

    for (int i = 1; i < n; ++i) {
      long long next = INT_MAX;
      for (int j = 0; j < primes.size(); ++j) {
        next = min(next, 1LL * ugly[index[j]] * primes[j]);
      }
      for (int j = 0; j < primes.size(); ++j) {
        if (1LL * ugly[index[j]] * primes[j] == next) {
          ++index[j];
        }
      }
      ugly[i] = next;
    }

    return ugly[n - 1];
  }
};
