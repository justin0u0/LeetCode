/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/max-number-of-k-sum-pairs/
 * Runtime: 225ms
 */

class Solution {
public:
  int maxOperations(vector<int>& nums, int k) {
    int pairs = 0;
    unordered_multiset<int> box;
    for (const int& val : nums) {
      unordered_multiset<int>::iterator it = box.find(k - val);
      if (it != box.end()) {
        ++pairs;
        box.erase(it);
      } else {
        box.emplace(val);
      }
    }

    return pairs;
  }
};
