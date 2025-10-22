/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/
 * Runtime: 212ms (75.83%)
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
    int j = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int l = lower_bound(nums.begin(), nums.end(), nums[i] - k) - nums.begin();
      int r = upper_bound(nums.begin(), nums.end(), nums[i] + k) - nums.begin();
      freq = max(freq, min(numOperations + count[nums[i]], r - l));

      while (nums[i] - nums[j] > k + k) {
        ++j;
      }
      freq = max(freq, min(numOperations, i - j + 1));
    }
    return freq;
  }
};
