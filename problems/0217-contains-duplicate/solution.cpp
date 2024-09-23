/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/contains-duplicate/
 * Runtime: 62ms (98.73%)
 */

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for (int num : nums) {
      if (s.find(num) != s.end()) {
        return true;
      }
      s.emplace(num);
    }
    return false;
  }
};
