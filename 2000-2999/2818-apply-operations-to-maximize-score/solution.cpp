/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/apply-operations-to-maximize-score/
 * Runtime: 282ms (74.39%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;

  long long pow(long long a, int p) {
    long long x = 1;
    while (p != 0) {
      if (p & 1) {
        x = (x * a) % mod;
      }
      a = (a * a) % mod;
      p >>= 1;
    }
    return x;
  }
public:
  int maximumScore(const vector<int>& nums, int k) {
    const int n = nums.size();
    vector<int> pscore(n, 0);

    for (int i = 0; i < n; ++i) {
      int x = nums[i];
      int& ps = pscore[i];
      for (int j = 2; x != 1 && j * j < nums[i]; ++j) {
        if (x % j == 0) {
          ++ps;
          while (x % j == 0) {
            x /= j;
          }
        }
      }
      if (x != 1) {
        ++ps;
      }
    }

    priority_queue<pair<int, long long>> pq; // [num, ops]
    stack<int> stk; // monotonic stack with decreasing sequence
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && pscore[stk.top()] < pscore[i]) {
        int j = stk.top();
        stk.pop();

        if (stk.empty()) { // stk.top() = -1
          pq.push({nums[j], 1LL * (j + 1) * (i - j)});
        } else {
          pq.push({nums[j], 1LL * (j - stk.top()) * (i - j)});
        }
      }
      stk.push(i);
    }
    while (!stk.empty()) {
      int j = stk.top();
      stk.pop();

      if (stk.empty()) {
        pq.push({nums[j], 1LL * (j + 1) * (n - j)});
      } else {
        pq.push({nums[j], 1LL * (j - stk.top()) * (n - j)});
      }
    }

    const int mod = 1e9 + 7;
    long long score = 1;
    while (k != 0) {
      auto [num, ops] = pq.top();
      pq.pop();

      ops = min(ops, (long long)k);
      score = (score * pow(num, ops)) % mod;
      k -= ops;
    }
    return score;
  }
};
