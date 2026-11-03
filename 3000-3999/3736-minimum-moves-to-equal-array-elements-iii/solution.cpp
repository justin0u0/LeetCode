/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minMoves(const vector<int>& nums) {
    const int target = *ranges::max_element(nums);
    int moves = 0;
    for (int num : nums) {
      moves += target - num;
    }
    return moves;
  }
};
