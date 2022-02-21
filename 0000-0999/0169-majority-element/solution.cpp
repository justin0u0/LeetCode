/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/majority-element/
 * Runtime: 19ms
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int x = nums[0];
    int c = 1;

    int n = (int)nums.size();
    for (int i = 1; i < n; ++i) {
      if (nums[i] == x) {
        ++c;
      } else {
        --c;
      }

      if (!c) {
        x = nums[i];
        c = 1;
      }
    }

    return x;
  }
};
