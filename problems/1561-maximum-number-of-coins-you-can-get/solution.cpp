/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
 * Runtime: 59ms (99.60%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxCoins(vector<int>& piles) {
    sort(piles.begin(), piles.end(), greater<int>());
    const int n = piles.size() / 3;
    int answer = 0;
    for (int i = 0, j = 1; i < n; ++i, j += 2) {
      answer += piles[j];
    }
    return answer;
  }
};
