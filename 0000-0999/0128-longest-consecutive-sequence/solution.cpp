/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-consecutive-sequence/
 * Runtime: 236ms
 * Time Complexity: O(N)
 */

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> box(nums.begin(), nums.end());

    int answer = 0;
    for (const int l : nums) {
      if (box.find(l - 1) == box.end()) {
        int r = l + 1;
        while (box.find(r) != box.end()) {
          ++r;
        }

        answer = max(answer, r - l);
      }
    }

    return answer;
  }
};
