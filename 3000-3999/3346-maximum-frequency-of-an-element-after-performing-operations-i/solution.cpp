/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/
 * Runtime: 266ms (42.96%)
 */

class Solution {
public:
  int maxFrequency(vector<int>& nums, int k, int numOperations) {
    sort(nums.begin(), nums.end());

    unordered_map<int, int> count;
    for (int num : nums) {
      ++count[num];
    }

    int freq = 0;
    for (int i = nums[0]; i <= nums.back(); ++i) {
      int l = lower_bound(nums.begin(), nums.end(), i - k) - nums.begin();
      int r = upper_bound(nums.begin(), nums.end(), i + k) - nums.begin();
      freq = max(freq, min(numOperations + count[i], r - l));
    }
    return freq;
  }
};
