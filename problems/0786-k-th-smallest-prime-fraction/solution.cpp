/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/k-th-smallest-prime-fraction/
 * Runtime: 3ms (96.73%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    // Find kth smallest equals to find Kth largest, where K=k-N*(N-1)/2+1.
    // Binary search X, find number of fractions >= X. If total == K, then the
    // smallest one is the answer.
    //
    // Sort the array increasingly. e.g.
    // arr = [1,2,3,5,7]
    // i=0 1/2 1/3 1/5 1/7
    // i=1     2/3 2/5 2/7
    // i=2         3/5 3/7
    // i=3             5/7
    //
    // If i/j > X, then all i'/j > X if i' > i, so we can keep j increasingly.

    sort(arr.begin(), arr.end());
    double l = 0;
    double r = 1;
    const int n = arr.size();
    k = n * (n - 1) / 2 - k + 1;
    while (r - l > 1e-6) {
      double mid = (l + r) / 2;
      int j = 1;
      int sum = 0;
      double minFrac = 1;
      int minFracI, minFracJ;
      for (int i = 0; i < n - 1; ++i) {
        while (j < n && (double)arr[i] / arr[j] > mid) {
          ++j;
        }
        const double f = (double)arr[i] / arr[j - 1];
        if (f < minFrac) {
          minFrac = f;
          minFracI = i;
          minFracJ = j - 1;
        }
        sum += j - i - 1;
      }
      if (sum == k) {
        return {arr[minFracI], arr[minFracJ]};
      }
      if (sum < k) {
        r = mid;
      } else {
        l = mid;
      }
    }
    return {};
  }
};
