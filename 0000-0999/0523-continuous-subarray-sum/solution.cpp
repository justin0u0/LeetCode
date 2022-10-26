/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/continuous-subarray-sum/
 * Runtime: 243ms (92.27%)
 */

class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    int sum = 0;
    int prev = 0;
    unordered_set<int> box;
    for (const int& num : nums) {
      sum = (sum + num) % k;
      if (box.find(sum) != box.end()) {
        return true;
      }

      box.emplace(prev);
      prev = sum;
    }

    return false;
  }
};
