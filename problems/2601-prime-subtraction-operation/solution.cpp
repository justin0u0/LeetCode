/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/prime-subtraction-operation/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  static vector<int> primes;
public:
  bool primeSubOperation(const vector<int>& nums) {
    int cap = INT_MAX;
    for (int i = nums.size() - 1; i >= 0; --i) {
      if (nums[i] < cap) {
        cap = nums[i];
        continue;
      }

      auto it = upper_bound(primes.begin(), primes.end(), nums[i] - cap);
      if (it == primes.end() || (*it) >= nums[i]) {
        return false;
      }
      cap = nums[i] - (*it);
    }
    return true;
  }
};

vector<int> Solution::primes = []() {
  const int N = 1000;
  vector<int> primes;
  vector<bool> p(N, false);
  p[0] = true;
  p[1] = true;

  for (int i = 2; i < N; ++i) {
    if (!p[i]) {
      primes.emplace_back(i);
    }
    for (int j = 0; i * primes[j] < N; ++j) {
      p[i * primes[j]] = true;
      if (i % primes[j] == 0) {
        break;
      }
    }
  }

  return primes;
}();
