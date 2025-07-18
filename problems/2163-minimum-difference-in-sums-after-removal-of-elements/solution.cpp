/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/
 * Runtime: 189ms (48.97%)
 */

class Solution {
public:
  long long minimumDifference(vector<int>& nums) {
    // Divides nums into nums[0:i) nums[i, 3*n),
    // pick the smallest n numbers from nums[0:i),
    // and largest n numbers from nums[i, 3*n)
    const int m = nums.size();
    const int n = m / 3;

    vector<long long> lmin(m);
    long long ls = 0;
    priority_queue<int> lpq;
    for (int i = 0; i < m; ++i) {
      lpq.push(nums[i]);
      ls += nums[i];
      if (lpq.size() > n) {
        ls -= lpq.top();
        lpq.pop();
      }
      lmin[i] = ls;
    }

    long long rs = 0;
    priority_queue<int, vector<int>, greater<int>> rpq;
    long long diff = 1e16;
    for (int i = m - 1; i >= n; --i) {
      rpq.push(nums[i]);
      rs += nums[i];
      if (rpq.size() > n) {
        rs -= rpq.top();
        rpq.pop();
      }

      if (i + n <= m) {
        diff = min(diff, lmin[i - 1] - rs);
      }
    }

    return diff;
  }
};
