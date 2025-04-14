/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-good-triplets/
 * Runtime: 6ms (78.59%)
 */

class Solution {
public:
  int countGoodTriplets(const vector<int>& arr, const int a, const int b, const int c) {
    const int n = arr.size();
    int count = 0;
    
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (abs(arr[i] - arr[j]) > a) {
          continue;
        }
        for (int k = j + 1; k < n; ++k) {
          if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
            ++count;
          }
        }
      }
    }

    return count;
  }
};
