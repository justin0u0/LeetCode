/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/
 * Runtime: 574ms (14.06%)
 */

class Solution {
public:
  long long minimumCost(vector<int>& nums, int k, int dist) {
    set<pair<int, int>> best; // minimum k - 2 elements in the sliding window
    set<pair<int, int>> cand; // other elements in the sliding window
    long long sum = 0;        // sum of elements in the `best` set
    long long res = 1e18;

    for (int i = 2; i < nums.size() + dist; ++i) {
      if (i - dist > 1) {
        pair<int, int> target{nums[i - dist], i - dist};
        if (cand.find(target) != cand.end()) {
          cand.erase(target);
        } else {
          best.erase(target);
          sum -= nums[i - dist];
        }
        if (best.size() < k - 2 && !cand.empty()) {
          auto it = cand.begin();
          best.insert(*it);
          sum += it->first;
          cand.erase(it);
        }
      }

      if (i < nums.size()) {
        best.insert({nums[i], i});
        sum += nums[i];
      }
      if (best.size() > k - 2) {
        auto it = prev(best.end());
        cand.insert(*it);
        sum -= it->first;
        best.erase(it);
      }

      if (best.size() >= k - 2) {
        res = min(res, nums[max(i - dist, 1)] + sum);
      }
    }

    return res + nums[0];
  }
};
