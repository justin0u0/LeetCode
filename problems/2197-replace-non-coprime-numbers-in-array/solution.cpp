/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/replace-non-coprime-numbers-in-array/
 * Runtime: 23ms (50.93%)
 */

class Solution {
public:
  vector<int> replaceNonCoprimes(vector<int>& nums) {
    int g;
    stack<int> stk;
    for (int num : nums) {
      while (!stk.empty() && (g = gcd(stk.top(), num)) != 1) {
        num = num / g * stk.top();
        stk.pop();
      }
      stk.push(num);
    }
    vector<int> res;
    res.reserve(stk.size());
    while (!stk.empty()) {
      res.emplace_back(stk.top());
      stk.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
