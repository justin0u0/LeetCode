/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> maxSumOfThreeSubarrays(const vector<int>& nums, const int k) {
    // Iterate the middle subarrays, maintains the maximum non-overlapping
    // subarrays, and pre-calculate the maximum subarray from the right.
    const int n = nums.size();

    // `rmxs[i]` is the sum of maximum sum subarray in nums[i:]
    vector<int> rmxs(n, 0);
    // `ris[i]` is the index of maximum sum subarray in nums[i:]
    vector<int> ris(n, 0);
    int rs = accumulate(nums.rbegin(), nums.rbegin() + k, 0);
    int rmx = rs;
    int ri = n - k;
    rmxs[n - k] = rmx;
    ris[n - k] = ri;
    for (int i = n - k - 1; i >= 0; --i) {
      rs += nums[i] - nums[i + k];
      if (rs >= rmx) { // keep the lexicographically smallest one
        rmx = rs;
        ri = i;
      }
      ris[i] = ri;
      rmxs[i] = rmx;
    }

    // `ls` is the sum of the left subarray during iteration
    int ls = accumulate(nums.begin(), nums.begin() + k, 0);
    // `lmx` is the sum of maximum sum subarray in nums[:i]
    int lmx = ls;
    // `li` is the index of maximum sum subarray in nums[:i]
    int li = 0;

    // `ms` is the sum of the middle subarray during iteration
    int ms = accumulate(nums.begin() + k, nums.begin() + k + k, 0);

    int mx = 0;
    vector<int> res(3);

    for (int i = k; i <= n - k - k; ++i) {
      const int sum = lmx + ms + rmxs[i + k];
      if (sum > mx) {
        mx = sum;
        res = {li, i, ris[i + k]};
      }

      ms += nums[i + k] - nums[i];
      ls += nums[i] - nums[i - k];
      if (ls > lmx) {
        lmx = ls;
        li = i - k + 1;
      }
    }

    return res;
  }
};
