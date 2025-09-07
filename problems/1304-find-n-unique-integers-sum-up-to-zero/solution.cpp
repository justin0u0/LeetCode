/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> sumZero(int n) {
    vector<int> res;
    res.reserve(n);
    for (int i = 1; i < n; i += 2) {
      res.emplace_back(i);
      res.emplace_back(-i);
    }
    if (n & 1) {
      res.emplace_back(0);
    }
    return res;
  }
};
