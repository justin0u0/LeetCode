/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/patching-array/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minPatches(const vector<int>& nums, const unsigned int n) {
    unsigned int largest = 0;
    int answer = 0;
    for (int i = 0; largest < n && i < nums.size(); ++i) {
      while (largest < n && largest + 1 < nums[i]) {
        largest += (largest + 1);
        ++answer;
      }
      largest += nums[i];
    }
    while (largest < n) {
      largest += (largest + 1);
      ++answer;
    }
    return answer;
  }
};
