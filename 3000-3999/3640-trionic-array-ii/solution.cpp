/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/trionic-array-ii/
 * Runtime: 19ms (60.00%)
 */

class Solution {
private:
  const long long INF = 1e16;
public:
  long long maxSumTrionic(const vector<int>& nums) {
    const int n = nums.size();

    // lmax[p]: maximum sum of stringly increasing nums[l...p]
    vector<long long> lmax(n, -INF);
    {
      long long sum = 0;
      for (int i = 1; i < n; ++i) {
        if (nums[i] > nums[i - 1]) {
          lmax[i] = nums[i] + nums[i - 1] + sum;
          sum = max(0LL, sum + nums[i - 1]);
        } else {
          sum = 0;
        }
      }
    }

    // rmax[q]: maximum sum of strictly increasing nums[q...r]
    vector<long long> rmax(n, -INF);
    {
      long long sum = 0;
      for (int i = n - 2; i >= 0; --i) {
        if (nums[i] < nums[i + 1]) {
          rmax[i] = nums[i] + nums[i + 1] + sum;
          sum = max(0LL, sum + nums[i + 1]);
        } else {
          sum = 0;
        }
      }
    }

    long long res = -INF;
    long long sum = 0;
    int j = -1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] < nums[i - 1]) {
        if (j == -1) {
          j = i - 1;
          sum = nums[i - 1];
        }
        sum += nums[i];
      } else if (j != -1) {
        // found p=j, q=i-1
        res = max(res, lmax[j] + sum + rmax[i - 1] - nums[j] - nums[i - 1]);
        j = -1;
      }
    }

    return res;
  }
};
