/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/
 * Runtime: 78ms (93.35%)
 */

class Solution {
private:
  pair<int, int> partition(const vector<int>& nums) {
    const int n = nums.size();
    pair<int, int> res{n, n};
    for (int i = 0; i < n; ++i) {
      if (nums[i] >= 0) {
        res.first = i;
        break;
      }
    }
    for (int i = n - 1; i >= 0; --i) {
      if (nums[i] <= 0) {
        res.second = n - i - 1;
        break;
      }
    }
    return res;
  }
public:
  long long kthSmallestProduct(const vector<int>& nums1, const vector<int>& nums2, long long k) {
    const int n = nums1.size();
    const int m = nums2.size();

    auto [neg1, pos1] = partition(nums1);
    auto [neg2, pos2] = partition(nums2);

    const long long neg = (long long)neg1 * pos2 + (long long)neg2 * pos1;
    if (neg >= k) {
      long long l = 0;
      long long r = 1e10 + 1;
      while (l <= r) {
        long long low = (l + r) >> 1;

        long long total = 0; // number of product <= -low
        int j = m - 1;
        for (int i = neg1 - 1; i >= 0; --i) {
          while (j >= m - pos2 && (long long)abs(nums1[i]) * nums2[j] >= low) {
            --j;
          }
          total += m - 1 - j;
        }

        j = n - 1;
        for (int i = neg2 - 1; i >= 0; --i) {
          while (j >= n - pos1 && (long long)abs(nums2[i]) * nums1[j] >= low) {
            --j;
          }
          total += n - 1 - j;
        }

        // cout << total << " number of product <= " << -low << endl;
        if (total >= k) {
          l = low + 1;
        } else {
          r = low - 1;
        }
      }
      return -l + 1; // -low
    }

    k -= neg;
    const long long zer = (long long)(n - neg1 - pos1) * m + (long long)(m - neg2 - pos2) * n - (long long)(n - neg1 - pos1) * (long long)(m - neg2 - pos2);
    if (zer >= k) {
      return 0;
    }
    k -= zer;

    long long l = 0;
    long long r = 1e10 + 1;
    while (l <= r) {
      long long cap = (l + r) >> 1;

      long long total = 0;
      int j = m - pos2;
      for (int i = n - 1; i >= n - pos1; --i) {
        while (j < m && (long long)nums1[i] * nums2[j] <= cap) {
          ++j;
        }
        total += j - m + pos2;
      }

      j = neg2 - 1;
      for (int i = 0; i < neg1; ++i) {
        while (j >= 0 && (long long)nums1[i] * nums2[j] <= cap) {
          --j;
        }
        total += neg2 - 1 - j;
      }

      // cout << total << " number of product <= " << cap << endl;
      if (total >= k) {
        r = cap - 1;
      } else {
        l = cap + 1;
      }
    }
    return r + 1;
  }
};
