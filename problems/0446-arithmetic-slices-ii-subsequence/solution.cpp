/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
 * Runtime: 916ms (82.44%)
 */

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();

    vector<gp_hash_table<long long, int>> seqs(n);
    int answer = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        long long diff = (long long)nums[i] - nums[j];
        if (diff > INT_MAX || diff < INT_MIN) {
          continue;
        }

        int seq = seqs[j][diff];
        answer += seq;
        seqs[i][diff] += seq + 1;
      }
    }

    return answer;
  }
};
