/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/subarray-sum-equals-k/
 * Runtime: 118ms
 */

class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> box;
    box.emplace(0, 1);

    int pre = 0;
    int answer = 0;
    for (const int& num : nums) {
      pre += num;
      answer += box[pre - k];

      ++box[pre];
    }

    return answer;
  }
};
