/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/three-consecutive-odds/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool threeConsecutiveOdds(const vector<int>& arr) {
    for (int i = 2; i < arr.size(); ++i) {
      if ((arr[i] & 1) && (arr[i - 1] & 1) && (arr[i - 2] & 1)) {
        return true;
      }
    }
    return false;
  }
};
