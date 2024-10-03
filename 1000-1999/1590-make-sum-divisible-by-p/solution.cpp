/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/make-sum-divisible-by-p/
 * Runtime: 92ms (99.49%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minSubarray(const vector<int>& nums, const int p) {
    long long total = accumulate(nums.begin(), nums.end(), 0LL);
    const int target = total % p;
    if (target == 0) {
      return 0;
    }

    const int n = nums.size();
    unordered_map<int, pair<int, long long>> m;
    m.emplace(0, pair{-1, 0});
    long long sum = 0;
    int answer = n;
    for (int i = 0; i < n; ++i) {
      sum += nums[i];

      auto it = m.find((sum % p - target + p) % p);
      if (it != m.end() && total - sum + it->second.second >= p) {
        answer = min(answer, i - it->second.first);
      }
      m[sum % p] = {i, sum};
    }

    if (answer == n) {
      return -1;
    }
    return answer;
  }
};
