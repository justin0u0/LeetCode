/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-music-playlists/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
  int dp[101][101];
public:
  int numMusicPlaylists(int n, int goal, int k) {
    dp[0][0] = 1;
    for (int i = 1; i <= goal; ++i) {
      for (int j = 1; j <= n; ++j) {
        int& d = dp[i][j];
        d = ((long long)dp[i - 1][j - 1] * (n - j + 1)) % mod;
        if (j >= k) {
          d = (d + ((long long)dp[i - 1][j] * (j - k)) % mod) % mod;
        }
      }
    }
    return dp[goal][n];
  }
};

// dp(i, j) i songs have been played, with j different songs
// dp(i, j) = dp(i - 1, j - 1) * (n - j + 1)
//            play a song that is never played, thus we have (n - j + 1) choices.
//          + dp(i - 1, j) * (j - k) if j >= k
//            play a song that is played, the recently k song cannot be played,
//            thus we have (j - k) choices.
