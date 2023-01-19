/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/subarray-sums-divisible-by-k/
 * Runtime: 36ms (98.69%)
 */

class Solution {
public:
  int subarraysDivByK(vector<int>& nums, int k) {
    vector<int> box(k, 0);
    box[0] = 1;

    int sum = 0;
    int answer = 0;
    for (const int& num : nums) {
      sum = ((sum + num) % k + k) % k;
      answer += box[sum];
      ++box[sum];
    }
    return answer;
  }
};
