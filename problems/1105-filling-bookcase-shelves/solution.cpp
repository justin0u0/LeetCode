/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/filling-bookcase-shelves/
 * Runtime: 3ms (87.31%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    // Assume the height and width of the ith book is H[i] and W[i], respectively.
    //
    // dp(i) is the minimum height shelves to fill books[0:i].
    //  dp(i) = min{dp(j) + max{H[j+1], H[j+2], ..., H[i]}},
    //    ∀j with W[j+1] + W[j+2] + ... + W[i] <= shelfWidth

    const int n = books.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
      int& d = dp[i + 1];
      int w = 0;
      int h = 0;
      for (int j = i; j >= 0; --j) {
        w += books[j][0];
        h = max(h, books[j][1]);
        if (w > shelfWidth) {
          break;
        }
        d = min(d, dp[j] + h);
      }
    }
    return dp[n];
  }
};
