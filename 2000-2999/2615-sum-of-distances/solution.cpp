/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sum-of-distances/
 * Runtime: 40ms (98.00%)
 */

class Solution {
private:
  struct Data {
    int last;
    int count;
    long long dist;
  };
public:
  vector<long long> distance(const vector<int>& nums) {
    const int n = nums.size();

    vector<long long> res(n, 0);
    unordered_map<int, Data> m;
    for (const auto [i, num] : nums | views::enumerate) {
      auto& [last, count, dist] = m[num];
      if (count > 0) {
        dist += static_cast<long long>(count) * (i - last);
        res[i] = dist;
      }
      ++count;
      last = i;
    }

    m.clear();
    for (const auto [i, num] : nums | views::enumerate | views::reverse) {
      auto& [last, count, dist] = m[num];
      if (count > 0) {
        dist += static_cast<long long>(count) * (last - i);
        res[i] += dist;
      }
      ++count;
      last = i;
    }

    return res;
  }
};
