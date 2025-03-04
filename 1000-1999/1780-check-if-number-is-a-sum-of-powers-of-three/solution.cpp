/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  static unordered_set<int> pof3;
public:
  bool checkPowersOfThree(int n) {
    return pof3.find(n) != pof3.end();
  }
};

unordered_set<int> Solution::pof3 = []() {
  const int n = 1e7;

  unordered_set<int> s;
  s.emplace(0);

  vector<int> box;

  for (int i = 1; i <= n; i *= 3) {
    box.clear();
    for (int k : s) {
      box.emplace_back(k + i);
    }
    for (int k : box) {
      s.emplace(k);
    }
  }

  return s;
}();
