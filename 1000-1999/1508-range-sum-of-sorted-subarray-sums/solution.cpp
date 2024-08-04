/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
 * Runtime: 3ms (97.53%)
 */

class Solution {
  // psum[i + 1] = nums[0] + nums[1] + ... + nums[i]
  vector<int> psum;
  // ppsum[i] = psum[0] + psum[1] + ... + psum[i]
  vector<int> ppsum;

  const int mod = 1e9 + 7;

  int sumByMaxSubarrays(const int n, const int maxSubarrays) {
    int l = 1;
    int r = 100001;
    long long res = 0;
    while (l < r) {
      int mid = (l + r) >> 1;

      int j = 0;
      // count is the number of subarrays with sum <= mid
      int count = 0;
      long long sum = 0;
      for (int i = 1; i <= n; ++i) {
        while (psum[i] - psum[j] > mid) {
          ++j;
        }

        // psum[j+1] + psum[j+2] + ... + psum[i]
        count += i - j;
        sum += psum[i] * (i - j) - (ppsum[i] - ppsum[j]);
        sum %= mod;
      }

      if (count >= maxSubarrays) {
        r = mid;
        res = sum - 1LL * (count - maxSubarrays) * mid;
      } else {
        l = mid + 1;
      }
    }

    return res % mod;
  }
public:
  int rangeSum(vector<int>& nums, int n, int left, int right) {
    psum.resize(n + 1);
    psum[0] = 0;
    for (int i = 0; i < n; ++i) {
      psum[i + 1] = psum[i] + nums[i];
    }

    ppsum.resize(n + 2);
    ppsum[0] = 0;
    for (int i = 0; i <= n; ++i) {
      ppsum[i + 1] = ppsum[i] + psum[i];
    }

    return sumByMaxSubarrays(n, right) - sumByMaxSubarrays(n, left - 1);
  }
};
