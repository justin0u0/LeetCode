/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/
 * Runtime: 35ms (61.24%)
 */

class Solution {
public:
  int partitionArray(vector<int>& nums, const int k) {
    sort(nums.begin(), nums.end());
    int part = 1;
    int j = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] - nums[j] > k) {
        j = i;
        ++part;
      }
    }
    return part;
  }
};
