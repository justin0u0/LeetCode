/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sum-of-even-numbers-after-queries/
 * Runtime: 103ms (98.61%)
 */

class Solution {
public:
  vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    int sum = 0;
    for (const int& val : nums) {
      if (!(val & 1)) {
        sum += val;
      }
    }

    vector<int> answer;
    answer.reserve(queries.size());
    for (const vector<int>& query : queries) {
      int& val = nums[query[1]];
      if (!(val & 1)) {
        sum -= val;
      }
      val += query[0];
      if (!(val & 1)) {
        sum += val;
      }
      answer.emplace_back(sum);
    }

    return answer;
  }
};
