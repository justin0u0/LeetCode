/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
 * Runtime: 3ms (73.02%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int numOfSubarrays(vector<int>& arr) {
    int odd = 0;
    int even = 1;
    int sum = 0;
    long long total = 0;
    for (int num : arr) {
      sum += num;
      if (sum & 1) {
        total += even;
        ++odd;
      } else {
        total += odd;
        ++even;
      }
    }
    return total % mod;
  }
};
