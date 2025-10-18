/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/
 * Runtime: 90ms (99.68%)
 */

class Solution {
public:
  int maxDistinctElements(vector<int>& nums, const int k) {
    int cap = INT_MIN;
    sort(nums.begin(), nums.end());

    int dist = 0;
    for (int num : nums) {
      if (num + k > cap) {
        ++dist;
        cap = max(cap + 1, num - k);
      }
    }
    return dist;
  }
};
