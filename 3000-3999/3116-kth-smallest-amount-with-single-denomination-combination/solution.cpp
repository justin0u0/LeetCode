/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/
 * Runtime: 207ms (16.28%)
 */

class Solution {
public:
  long long findKthSmallest(const vector<int>& coins, const int k) {
    const auto n = coins.size();

    long long l = 1;
    long long r = 1e12;

    while (l < r) {
      const auto mid = (l + r) >> 1;

      long long cnt = 0;

      for (int i = 1; i < (1 << n); ++i) {
        int sel = 0;
        long long lcm = 1;
        for (int j = 0; j < n; ++j) {
          if (i & (1 << j)) {
            ++sel;
            lcm = lcm * coins[j] / gcd(lcm, coins[j]);
          }
        }

        if (sel & 1) {
          cnt += mid / lcm;
        } else {
          cnt -= mid / lcm;
        }
      }

      if (cnt >= k) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    return r;
  }
};
