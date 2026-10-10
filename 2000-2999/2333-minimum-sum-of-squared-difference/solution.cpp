/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-sum-of-squared-difference/
 * Runtime: 23ms (38.55%)
 */

class Solution {
public:
  long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
    const int n = nums1.size();
    for (int i = 0; i < n; ++i) {
      nums1[i] = abs(nums1[i] -  nums2[i]);
    }
    ranges::sort(nums1);

    int l = 0;
    int r = 1e5 + 1;
    while (l < r) {
      const int mid = (l + r) >> 1;
      int k = k1 + k2;

      for (int i = 0; i < n; ++i) {
        k -= max(0, nums1[i] - mid);
        if (k < 0) {
          break;
        }
      }
      if (k >= 0) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    int k = k1 + k2;
    for (int i = 0; i < n; ++i) {
      if (nums1[i] >= r) {
        k -= nums1[i] - r;
        nums1[i] = r;
      }
    }

    for (int i = n - 1; i >= 0 && k > 0; --i) {
      if (nums1[i] > 0) {
        --nums1[i];
        --k;
      }
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += (long long)nums1[i] * nums1[i];
    }
    return ans;
  }
};
