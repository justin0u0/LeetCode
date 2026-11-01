/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minMoves(const vector<int>& nums) {
    const int target = *ranges::min_element(nums);
    int moves = 0;
    for (int num : nums) {
      moves += num - target;
    }
    return moves;
  }
};
