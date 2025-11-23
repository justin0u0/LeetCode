/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/greatest-sum-divisible-by-three/
 * Runtime: 3ms (86.49%)
 */

class Solution {
public:
  int maxSumDivThree(const vector<int>& nums) {
    int sum = 0;
    vector<int> mn1{(int)1e9, (int)1e9};
    vector<int> mn2{(int)1e9, (int)1e9};
    for (int num : nums) {
      sum += num;
      if (num % 3 == 1) {
        if (num < mn1[0]) {
          mn1[1] = mn1[0];
          mn1[0] = num;
        } else if (num < mn1[1]) {
          mn1[1] = num;
        }
      } else if (num % 3 == 2) {
        if (num < mn2[0]) {
          mn2[1] = mn2[0];
          mn2[0] = num;
        } else if (num < mn2[1]) {
          mn2[1] = num;
        }
      }
    }

    if (sum % 3 == 0) {
      return sum;
    }
    if (sum % 3 == 1) {
      return max(0, max(sum - mn1[0], sum - mn2[0] - mn2[1]));
    }
    return max(0, max(sum - mn2[0], sum - mn1[0] - mn1[1]));
  }
};
