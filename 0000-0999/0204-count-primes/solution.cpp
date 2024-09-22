/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-primes/
 * Runtime: 87ms (98.69%)
 */

class Solution {
private:
  const static int N = 5e6;
  static vector<int> primes;
public:
  int countPrimes(int n) {
    return lower_bound(primes.begin(), primes.end(), n) - primes.begin();
  }
};

vector<int> Solution::primes = []() {
  vector<bool> p(N + 1, false);
  vector<int> primes;

  p[0] = true;
  p[1] = true;

  for (int i = 2; i <= N; ++i) {
    if (!p[i]) {
      primes.emplace_back(i);
    }
    for (int j = 0; i * primes[j] <= N; ++j) {
      p[i * primes[j]] = true;
      if (i % primes[j] == 0) {
        break;
      }
    }
  }

  return primes;
}();
