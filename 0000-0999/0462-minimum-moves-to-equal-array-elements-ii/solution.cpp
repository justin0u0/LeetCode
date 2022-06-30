/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
 * Runtime: 12ms
 */

class Solution {
public:
  int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int mid = nums[nums.size() / 2];
    int answer = 0;
    for (const int num : nums) {
      answer += abs(num - mid);
    }

    return answer;
  }
};
