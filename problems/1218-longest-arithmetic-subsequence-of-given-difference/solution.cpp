/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
 * Runtime: 136ms (95.43%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int longestSubsequence(const vector<int>& arr, int difference) {
    unordered_map<int, int> dp;
    int answer = 1;
    for (const int val : arr) {
      auto it = dp.find(val - difference);
      if (it == dp.end()) {
        dp.emplace(val, 1);
      } else {
        int& d = dp[val];
        d = max(d, it->second + 1);
        answer = max(answer, d);
      }
    }
    return answer;
  }
};
