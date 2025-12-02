/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-number-of-trapezoids-i/
 * Runtime: 61ms (76.84%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int countTrapezoids(const vector<vector<int>>& points) {
    unordered_map<int, int> m;
    for (const auto& point : points) {
      ++m[point[1]];
    }

    vector<long long> nums;
    for (const auto [_, cnt] : m) {
      if (cnt > 1) {
        nums.push_back((long long)cnt * (cnt - 1) / 2);
      }
    }
    if (nums.size() < 2) {
      return 0;
    }

    int res = 0;
    long long sum = 0;
    for (long long num : nums) {
      res = (res + sum * num) % mod;
      sum += num;
    }
    return res;
  }
};
