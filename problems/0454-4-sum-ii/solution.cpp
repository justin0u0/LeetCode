/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/4sum-ii/
 * Runtime: 180ms
 */

class Solution {
public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int, int> box;

    for (const int& lhs : nums1) {
      for (const int& rhs : nums2) {
        ++box[lhs + rhs];
      }
    }

    int answer = 0;
    for (const int& lhs : nums3) {
      for (const int& rhs : nums4) {
        answer += box[-lhs - rhs];
      }
    }

    return answer;
  }
};
