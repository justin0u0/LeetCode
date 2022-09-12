/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/bag-of-tokens/
 * Runtime: 3ms
 */

class Solution {
public:
  int bagOfTokensScore(vector<int>& tokens, int power) {
    int n = tokens.size();
    sort(tokens.begin(), tokens.end());

    int l = 0;
    int score = 0;
    for (int r = n; r > l; ) {
      while (l < r && power >= tokens[l]) {
        power -= tokens[l];
        ++l;
      }
      int s = l + r - n;
      score = max(score, s);

      if (s < 1) {
        break;
      }

      --r;
      power += tokens[r];
    }

    return score;
  }
};
