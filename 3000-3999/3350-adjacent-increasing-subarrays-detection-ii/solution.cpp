/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/
 * Runtime: 106ms (98.12%)
 */

class Solution {
public:
  int maxIncreasingSubarrays(const vector<int>& nums) {
    int cnt = 1;
    int pre = 0;
    int res = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        ++cnt;
      } else {
        pre = cnt;
        cnt = 1;
      }
      res = max(res, min(cnt, pre));
      res = max(res, cnt / 2);
    }
    return res;
  }
};
