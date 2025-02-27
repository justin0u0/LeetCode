/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
 * Runtime: 319ms (47.86%)
 */

class Solution {
private:
  int dp[1001][1001];
public:
  int lenLongestFibSubseq(vector<int>& arr) {
    const int n = arr.size();

    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
      m.emplace(arr[i], i);
      for (int j = 0; j < n; ++j) {
        dp[i][j] = 0;
      }
    }

    int longest = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        int prev = arr[i] - arr[j];
        auto it = m.find(prev);
        if (it != m.end() && prev < arr[j]) {
          dp[j][i] = dp[it->second][j] + 1;
        } else {
          dp[j][i] = 2;
        }
        longest = max(longest, dp[j][i]);
      }
    }

    if (longest < 3) {
      return 0;
    }
    return longest;
  }
};
