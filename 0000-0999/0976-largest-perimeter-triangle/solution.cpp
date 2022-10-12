/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/largest-perimeter-triangle/
 * Runtime: 41ms (91.76%)
 */

class Solution {
public:
  int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());

    int n = nums.size();
    for (int i = 0; i < n - 2; ++i) {
      if (nums[i + 1] + nums[i + 2] > nums[i]) {
        return nums[i] + nums[i + 1] + nums[i + 2];
      }
    }

    return 0;
  }
};
