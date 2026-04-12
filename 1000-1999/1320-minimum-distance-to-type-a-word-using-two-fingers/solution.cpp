/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/
 * Runtime: 27ms (46.59%)
 */

class Solution {
private:
  int dp[302][302];

  using Dist = array<array<int, 128>, 128>;

  inline static const Dist dist = [] {
    Dist d{};
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) {
        d[i + 'A'][j + 'A'] = abs(i / 6 - j / 6) + abs(i % 6 - j % 6);
      }
    }
    return d;
  }();
public:
  int minimumDistance(const string& word) {
    /*
      dp[i][j]: left hand at word[i], right hand at word[j]
       -> left hand move to the next word: dp[max(i, j) + 1][j]
       -> right hand move to the next word: dp[i][max(i, j) + 1]
    */

    const int n = word.length();
    memset(dp, -1, sizeof(dp));

    auto solve = [&](this auto&& self, int i, int j) {
      if (i == n || j == n) {
        return 0;
      }

      if (dp[i][j] != -1) {
        return dp[i][j];
      }

      int next = max(i, j) + 1;

      int left = self(next, j) + (i > 0 ? dist[word[i - 1]][word[next - 1]] : 0);
      int right = self(i, next) + (j > 0 ? dist[word[j - 1]][word[next - 1]] : 0);
      return (dp[i][j] = min(left, right));
    };

    return solve(0, 0);
  }
};
