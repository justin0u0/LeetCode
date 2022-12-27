/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/
 * Runtime: 183ms (97.80%)
 */

class Solution {
public:
  int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    int n = capacity.size();
    for (int i = 0; i < n; ++i) {
      capacity[i] -= rocks[i];
    }
    sort(capacity.begin(), capacity.end());
    for (int i = 0; i < n; ++i) {
      if (capacity[i] > additionalRocks) {
        return i;
      }
      additionalRocks -= capacity[i];
    }
    return n;
  }
};
