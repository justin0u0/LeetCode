/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-lucky-integer-in-an-array/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int findLucky(vector<int>& arr) {
    int freq[501] = {0};
    for (int num : arr) {
      ++freq[num];
    }

    int res = -1;
    for (int num : arr) {
      if (freq[num] == num) {
        freq[num] = 0;
        res = max(res, num);
      }
    }
    return res;
  }
};
