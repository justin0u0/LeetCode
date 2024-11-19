/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
 * Runtime: 3ms (98.80%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  int count[100001];
public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    nums.emplace_back(0);

    int card = 0;
    long long sum = 0;
    
    for (int i = 0; i < k; ++i) {
      if (++count[nums[i]] == 1) {
        ++card;
      }
      sum += nums[i];
    }

    long long res = 0;
    for (int i = k; i < nums.size(); ++i) {
      if (card == k) {
        res = max(res, sum);
      }

      sum += nums[i] - nums[i - k];

      if (++count[nums[i]] == 1) {
        ++card;
      }
      if (--count[nums[i - k]] == 0) {
        --card;
      }
    }

    return res;
  }
};
