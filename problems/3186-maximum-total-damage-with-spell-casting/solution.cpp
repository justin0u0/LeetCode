/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-total-damage-with-spell-casting/
 * Runtime: 368ms (30.65%)
 */

class Solution {
public:
  long long maximumTotalDamage(const vector<int>& power) {
    map<int, long long> m;
    for (const int p : power) {
      m[p] += p;
    }

    vector<pair<int, long long>> arr;
    for (const auto [k, v] : m) {
      arr.push_back({k, v});
    }

    const int n = arr.size();
    vector<pair<int, long long>> best{{-9, 0}, {-9, 0}, {-9, 0}};
    for (int i = 0; i < n; ++i) {
      pair<int, long long> next;
      for (int j = 0; j < 3; ++j) {
        if (best[j].first < arr[i].first - 2) {
          next = {arr[i].first, arr[i].second + best[j].second};
          break;
        }
      }
      if (next.second > best[0].second) {
        best[2] = best[1];
        best[1] = best[0];
        best[0] = next;
      } else if (next.second > best[1].second) {
        best[2] = best[1];
        best[1] = next;
      } else if (next.second > best[2].second) {
        best[2] = next;
      }
    }

    return max(max(best[0].second, best[1].second), best[2].second);
  }
};
