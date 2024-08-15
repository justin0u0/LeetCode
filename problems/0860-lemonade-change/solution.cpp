/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/lemonade-change/
 * Runtime: 53ms (97.85%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  bool lemonadeChange(vector<int>& bills) {
    int five = 0;
    int ten = 0;
    for (int b : bills) {
      if (b == 5) {
        ++five;
      } else if (b == 10) {
        if (five == 0) {
          return false;
        }
        --five;
        ++ten;
      } else if (b == 20) {
        if (five == 0 || (ten == 0 && five < 3)) {
          return false;
        }
        if (ten != 0) {
          --ten;
          --five;
        } else {
          five -= 3;
        }
      }
    }
    return true;
  }
};
