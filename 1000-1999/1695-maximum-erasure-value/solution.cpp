/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-erasure-value/
 * Runtime: 197ms
 */

class Solution {
public:
  int maximumUniqueSubarray(vector<int>& nums) {
    vector<int> cnt(10001);

    vector<int>::iterator lit = nums.begin();
    int answer = 0;
    int sum = 0;
    for (vector<int>::iterator rit = nums.begin(); rit != nums.end(); ++rit) {
      ++cnt[*rit];
      sum += (*rit);

      while (cnt[*rit] > 1) {
        --cnt[*lit];
        sum -= (*lit);
        ++lit;
      }

      answer = max(answer, sum);
    }

    return answer;
  }
};
