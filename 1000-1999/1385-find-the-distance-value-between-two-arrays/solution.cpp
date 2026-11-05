/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
 * Runtime: 1ms (48.66%)
 */

class Solution {
public:
  int findTheDistanceValue(const vector<int>& arr1, const vector<int>& arr2, const int d) {
    int ans = 0;

    for (int num1 : arr1) {
      bool ok = true;
      for (int num2 : arr2) {
        if (abs(num1 - num2) <= d) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ++ans;
      }
    }

    return ans;
  }
};
