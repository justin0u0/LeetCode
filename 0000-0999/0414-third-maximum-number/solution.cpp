/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/third-maximum-number/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int thirdMax(const vector<int>& nums) {
    int a = INT_MIN;
    int b = INT_MIN;
    int c = INT_MIN;

    int updates = 0;
    bool hasIntMin = false;
    for (int num : nums) {
      if (num > a) {
        c = b;
        b = a;
        a = num;
        ++updates;
      } else if (num < a && num > b) {
        c = b;
        b = num;
        ++updates;
      } else if (num < b && num > c) {
        c = num;
        ++updates;
      }
      
      if (num == INT_MIN) {
        hasIntMin = true;
      }
    }
    
    if (updates + hasIntMin >= 3) {
      return c;
    }
    return a;
  }
};
