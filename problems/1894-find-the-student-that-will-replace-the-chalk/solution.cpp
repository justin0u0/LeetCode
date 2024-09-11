/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
 * Runtime: 57ms (89.49%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int chalkReplacer(vector<int>& chalk, int k) {
    int sum = 0;
    for (int i = 0; i < chalk.size(); ++i) {
      sum += chalk[i];
      if (sum > k) {
        return i;
      }
    }

    k -= k / sum * sum;
    for (int i = 0; i < chalk.size(); ++i) { 
      k -= chalk[i];
      if (k < 0) {
        return i;
      }
    }

    return -1;
  }
};
