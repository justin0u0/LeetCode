/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
 * Runtime: 24ms (99.82%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    const int n = nums.size();

    map<int, vector<int>> sweepline;
    for (int i = 0; i < n; ++i) {
      for (int num : nums[i]) {
        sweepline[num].emplace_back(i);
      }
    }

    vector<int> count(n, 0);
    int nonZeros = 0;

    auto it = sweepline.begin();
    int shortest = INT_MAX;
    vector<int> answer;
    for (const auto [num, lists] : sweepline) {
      for (int list : lists) {
        if (count[list]++ == 0) {
          nonZeros++;
        }
      }

      while (nonZeros == n) {
        if (num - it->first < shortest) {
          shortest = num - it->first;
          answer = {it->first, num};
        }
        for (int list : it->second) {
          if (--count[list] == 0) {
            --nonZeros;
          }
        }
        ++it;
      }
    }

    return answer;
  }
};
