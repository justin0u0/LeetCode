/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/binary-trees-with-factors/
 * Runtime: 130ms
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int numFactoredBinaryTrees(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    unordered_map<int, int> dp;
    int answer = 0;
    for (int i = 0; i < arr.size(); ++i) {
      dp.emplace(arr[i], 1);
      for (int j = i - 1; j >= 0; --j) {
        if (arr[i] % arr[j] == 0) {
          dp[arr[i]] = (dp[arr[i]] + 1LL * dp[arr[j]] * dp[arr[i] / arr[j]]) % mod;
        }
      }
      answer = (answer + dp[arr[i]]) % mod;
    }

    return answer;
  }
};
