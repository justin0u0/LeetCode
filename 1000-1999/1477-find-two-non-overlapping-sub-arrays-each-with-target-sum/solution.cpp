/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minSumOfLengths(const vector<int>& arr, const int target) {
    const int n = arr.size();

    int j = 0;
    int sum = 0;

    // best[i]: minimum length of the sub-array with a sum equal `target`
    //  of arr[0:i]
    vector<int> best(n);
    int minLen = INT_MAX;

    int ans = INT_MAX;

    for (int i = 0; i < n; ++i) {
      sum += arr[i];
      while (sum > target) {
        sum -= arr[j];
        ++j;
      }
      if (sum == target) {
        const int len = i - j + 1;
        if (j > 0 && best[j - 1] != INT_MAX) {
          ans = min(ans, best[j - 1] + len);
        }
        minLen = min(minLen, len);
      }
      best[i] = minLen;
    }

    if (ans == INT_MAX) {
      return -1;
    }
    return ans;
  }
};
