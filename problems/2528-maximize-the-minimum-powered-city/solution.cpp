/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximize-the-minimum-powered-city/
 * Runtime: 87ms (76.34%)
 */

class Solution {
public:
  long long maxPower(const vector<int>& stations, const int r, const int k) {
    const int n = stations.size();

    auto check = [&](long long low) {
      vector<int> arr = stations;
      long long build = 0;
      long long p = 0;
      for (int i = 0; i < r; ++i) {
        p += arr[i];
      }
      for (int i = 0; i < n; ++i) {
        if (i + r < n) {
          p += arr[i + r];
        }
        if (i - r - 1 >= 0) {
          p -= arr[i - r - 1];
        }
        if (p < low) {
          build += low - p;
          arr[min(i + r, n - 1)] += low - p;
          p = low;
          if (build > k) {
            return false;
          }
        }
      }
      return true;
    };

    long long lo = 0;
    long long hi = 1e10 + 1e9 + 1;
    while (lo < hi) {
      long long mid = (lo + hi) >> 1;
      if (check(mid)) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    return lo - 1;
  }
};
