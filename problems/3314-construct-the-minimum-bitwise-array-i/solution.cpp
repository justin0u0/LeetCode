/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/
 * Runtime: 3ms (37.87%)
 */

class Solution {
public:
  vector<int> minBitwiseArray(vector<int>& nums) {
    unordered_map<int, int> s;
    for (int num : nums) {
      s.emplace(num, -1);
    }
    for (int i = 1000; i >= 0; --i) {
      const int o = i | (i + 1);
      auto it = s.find(o);
      if (it != s.end()) {
        it->second = i;
      }
    }
    for (int& num : nums) {
      num = s.at(num);
    }
    return nums;
  }
};
