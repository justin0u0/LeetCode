/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/closest-prime-numbers-in-range/
 * Runtime: 3ms (92.22%)
 */

class Solution {
private:
  static vector<int> primes;
public:
  vector<int> closestPrimes(int left, int right) {
    int l = lower_bound(primes.begin(), primes.end(), left) - primes.begin();

    vector<int> p{-1, -1};
    int dist = INT_MAX;

    int prev = primes[l];
    for (int i = l + 1; primes[i] <= right; ++i) {
      if (primes[i] - prev < dist) {
        dist = primes[i] - prev;
        p = {prev, primes[i]};
      }
      prev = primes[i];
    }
    return p;
  }
};

vector<int> Solution::primes = []() {
  const int n = 1e6 + 50;

  vector<int> v;
  vector<bool> p(n, false);
  
  for (int i = 2; i < n; ++i) {
    if (!p[i]) {
      v.emplace_back(i);
    }
    for (int j = 0; i * v[j] < n; ++j) {
      p[i * v[j]] = true;
      if (i % v[j] == 0) {
        break;
      }
    }
  }

  return v;
}();
