/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-building-height/
 * Runtime: 209ms (5.55%)
 */

class Solution {
public:
  int maxBuilding(int n, vector<vector<int>>& restrictions) {
    ranges::sort(restrictions, {}, [](const auto& res) {
      return res[1];
    });

    map<int, int> m;
    m.emplace(1, 0);
    m.emplace(n + 1, n);

    int maxh = 0;

    for (const auto& res : restrictions) {
      auto right = m.upper_bound(res[0]);
      auto left = prev(right);

      auto h = min(res[1], min(
        left->second + res[0] - left->first,
        right->second + right->first - res[0]
      ));
      m.emplace(res[0], h);
      maxh = max(maxh, h);
    }

    m.erase(n + 1);

    for (auto left = m.begin(); left != m.end(); ++left) {
      auto right = next(left);
      if (right != m.end()) {
        const auto dist = right->first - left->first;
        const auto high = max(left->second, right->second);
        const auto low = min(left->second, right->second);
        if (high - low < dist){
          maxh = max(maxh, high + (dist - (high - low)) / 2);
        }
      } else {
        maxh = max(maxh, left->second + n - left->first);
      }
    }

    return maxh;
  }
};
