/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/
 * Runtime: 323ms (72.72%)
 */

class Solution {
public:
  long long minTime(const vector<int>& skill, const vector<int>& mana) {
    const int n = skill.size();
    const int m = mana.size();

    vector<long long> time(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
      time[i] = time[i - 1] + skill[i - 1] * mana[0];
    }
    for (int j = 1; j < m; ++j) {
      long long shift = 0;
      time[0] = time[1];
      for (int i = 1; i <= n; ++i) {
        time[i] = time[i - 1] + skill[i - 1] * mana[j];
        shift = max(shift, time[i + 1] - time[i]);
      }
      for (int i = 0; i <= n; ++i) {
        time[i] += shift;
      }
    }

    return time[n];
  }
};
