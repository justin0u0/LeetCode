/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
 * Runtime: 106ms (93.88%)
 */

class Solution {
public:
  long long countSubarrays(const vector<int>& nums, int minK, int maxK) {
    int l = -1;
    int lMin = -1;
    int lMax = -1;

    long long answer = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int v = nums[i];
      if (v == minK) {
        lMin = i;
      }
      if (v == maxK) {
        lMax = i;
      }
      if (v < minK || v > maxK) {
        l = i;
        lMin = -1;
        lMax = -1;
      }
      if (lMin != -1 && lMax != -1) {
        answer += min(lMin, lMax) - l;
      }
    }
    return answer;
  }
};
