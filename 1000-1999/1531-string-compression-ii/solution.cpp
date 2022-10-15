/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/string-compression-ii/
 * Runtime: 44ms (87.88%)
 */

class Solution {
private:
  const int INF = 0x3f3f3f3f;
  const int levels[5] = {0, 1, 9, 99};

  int runLength(int count) {
    for (int i = 0; i < 5; ++i) {
      if (levels[i] >= count) {
        return i;
      }
    }

    return 4;
  }

  class T {
  public:
    int from; // transform from
    int len;  // added length
    int del;  // chars deleted
  };
public:
  int getLengthOfOptimalCompression(string& s, int k) {
    vector<pair<char, int>> box{pair{'?', 0}};
    for (const char c : s) {
      if (box.back().first == c) {
        ++box.back().second;
      } else {
        box.emplace_back(pair{c, 1});
      }
    }

    int n = box.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
      vector<T> trans;
      char c = box[i].first;
      int count = box[i].second;
      int len = runLength(count);

      // remove some `c` to make length shorter
      trans.emplace_back(T{i - 1, len, 0});
      for (int j = len - 1; j >= 0; --j) {
        trans.emplace_back(T{i - 1, j, count - levels[j]});
      }

      // combine previous `c` to make length shorter
      int d = 0;
      for (int j = i - 1; j > 0; --j) {
        if (box[j].first != c) {
          d += box[j].second;
        } else {
          count += box[j].second;
          trans.emplace_back(T{j - 1, runLength(count), d});
        }
      }

      dp[i][0] = dp[i - 1][0] + len;
      for (int j = 1; j <= k; ++j) {
        for (const T& t : trans) {
          if (t.del <= j) {
            dp[i][j] = min(dp[i][j], dp[t.from][j - t.del] + t.len);
          }
        }
      }
    }

    int answer = INF;
    for (int i = 0; i <= k; ++i) {
      answer = min(answer, dp[n][i]);
    }
    return answer;
  }
};
