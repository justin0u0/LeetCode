/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-cost-to-make-array-equal/
 * Runtime: 60ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long minCost(vector<int>& nums, vector<int>& cost) {
    int n = nums.size();
    vector<pair<int, int>> arr(nums.size());
    for (int i = 0; i < n; ++i) {
      arr[i] = {nums[i], cost[i]};
    }
    sort(arr.begin(), arr.end());

    long long cur = 0;
    long long rsum = 0;
    for (int i = 0; i < n; ++i) {
      cur += (long long)(arr[i].first - arr[0].first) * arr[i].second;
      rsum += arr[i].second;
    }

    long long answer = cur;
    long long lsum = 0;
    for (int i = 0; i < n - 1; ++i) {
      lsum += arr[i].second;
      rsum -= arr[i].second;
      cur += (lsum - rsum) * (arr[i + 1].first - arr[i].first);
      answer = min(answer, cur);
    }
    return answer;
  }
};
