/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/24-game/
 * Runtime: 3ms (90.31%)
 */

class Solution {
private:
  inline double c(const double a, const double b, const int op) {
    switch (op) {
      case 0:
        return a + b;
      case 1:
        return a - b;
      case 2:
        return a * b;
      case 3:
        if (b == 0) {
          return -10000;
        }
        return a / b;
    }
    return -10000;
  }

  const double ep = 1e-6;

  inline bool judge(const double d) {
    return d >= 24 - ep && d <= 24 + ep;
  }
public:
  bool judgePoint24(vector<int>& cards) {
    sort(cards.begin(), cards.end());
    
    do {
      vector<int> a = cards;
      for (int i = 0; i < 64; ++i) {
        vector<int> o = {i & 3, (i & 12) >> 2, (i & 48) >> 4};
        // 0, 1, 2
        if (judge(c(c(c(a[0], a[1], o[0]), a[2], o[1]), a[3], o[2]))) {
          return true;
        }
        // 0, 2, 1 = 1, 2, 0
        if (judge(c(c(a[0], a[1], o[0]), c(a[2], a[3], o[2]), o[1]))) {
          return true;
        }
        // 1, 0, 2
        if (judge(c(c(a[0], c(a[1], a[2], o[1]), o[0]), a[3], o[2]))) {
          return true;
        }
        // 2, 0, 1
        if (judge(c(a[0], c(c(a[1], a[2], o[1]), a[3], o[2]), o[0]))) {
          return true;
        }
        // 2, 1, 0
        if (judge(c(a[0], c(a[1], c(a[2], a[3], o[2]), o[1]), o[0]))) {
          return true;
        }
      }
    } while (next_permutation(cards.begin(), cards.end()));

    return false;
  }
};
