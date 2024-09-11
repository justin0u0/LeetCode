/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-missing-observations/
 * Runtime: 83ms (86.77%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int sum = 0;
    for (int r : rolls) {
      sum += r;
    }

    sum = mean * (n + rolls.size()) - sum;
    if (sum < n || sum > 6 * n) {
      return vector<int>{};
    }

    vector<int> missing(n);
    for (int i = 0; i < n; ++i) {
      missing[i] = sum / n + (i < sum % n);
    }
    return missing;
  }
};
