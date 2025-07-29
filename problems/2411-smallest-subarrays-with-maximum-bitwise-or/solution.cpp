/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/
 * Runtime: 15ms (93.10%)
 */

class Solution {
public:
  vector<int> smallestSubarrays(vector<int>& nums) {
    const int n = nums.size();
    vector<int> maxOr(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
      maxOr[i] = maxOr[i + 1] | nums[i];
    }

    int bits[32] = {0};
    int j = 0;
    int o = 0;
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
      while (o != maxOr[i]) {
        o |= nums[j];
        for (int k = 0, x = nums[j]; x != 0; x >>= 1, ++k) {
          bits[k] += (x & 1);
        }
        ++j;
      }
      res[i] = max(j - i, 1);

      for (int k = 0, x = nums[i]; x != 0; x >>= 1, ++k) {
        bits[k] -= (x & 1);
        if (bits[k] == 0) {
          o &= ~(1 << k);
        }
      }
    }
    return res;
  }
};
