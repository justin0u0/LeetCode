/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/arithmetic-slices/
 * Runtime: 3ms
 */

class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int n = (int)nums.size();

    int diff = 0x3f3f3f3f;
    int count = 0;
    int answer = 0;
    for (int i = 1; i < n; ++i) {
      if (nums[i] - nums[i - 1] == diff) {
        ++count;
      } else {
        if (count >= 2) {
          answer += (count - 1) * count / 2;
        }

        diff = nums[i] - nums[i - 1];
        count = 1;
      }
    }

    if (count >= 2) {
      answer += (count - 1) * count / 2;
    }

    return answer;
  }
};
