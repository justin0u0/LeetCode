/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-complete-subarrays-in-an-array/
 * Runtime: 21ms (56.49%)
 */

class Solution {
public:
  int countCompleteSubarrays(const vector<int>& nums) {
    unordered_set<int> us;
    for (int num : nums) {
      us.emplace(num);
    }

    const int target = us.size();
    const int n = nums.size();

    int arrs = 0;

    unordered_map<int, int> m;
    int j = 0;
    for (int i = 0; i < n; ++i) {
      auto it = m.find(nums[i]);
      if (it == m.end()) {
        m.emplace(nums[i], 1);
      } else {
        ++it->second;
      }

      while (m.size() >= target) {
        if (--m.at(nums[j]) == 0) {
          m.erase(nums[j]);
        }
        ++j;
      }
      arrs += j;
    }

    return arrs;
  }
};
