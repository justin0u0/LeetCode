/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/grumpy-bookstore-owner/
 * Runtime: 17ms (91.47%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxSatisfied(const vector<int>& customers, const vector<int>& grumpy, const int minutes) {
    int sum = 0;
    int add = 0;
    int maxa = 0;
    for (int i = 0; i < customers.size(); ++i) {
      if (grumpy[i]) {
        add += customers[i];
      } else {
        sum += customers[i];
      }
      if (i >= minutes && grumpy[i - minutes]) {
        add -= customers[i - minutes];
      }
      maxa = max(maxa, add);
    }
    return sum + maxa;
  }
};
