/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/
 * Runtime: 820ms (40.38%)
 */

class Solution {
public:
  vector<long long> findXSum(vector<int>& nums, int k, int x) {
    set<pair<int, int>> hi;
    set<pair<int, int>> lo;
    unordered_map<int, int> freq;

    long long sum = 0;

    auto add = [&](int f, int num) {
      sum += (long long)f * num;
      hi.insert({f, num});
      if (hi.size() > x) {
        auto it = hi.begin();
        sum -= (long long)it->first * it->second;
        lo.insert(*it);
        hi.erase(it);
      }
    };

    auto remove = [&](int f, int num) {
      auto it = hi.find({f, num});
      if (it != hi.end()) {
        sum -= (long long)it->first * it->second;
        hi.erase(it);
        if (hi.size() < x && !lo.empty()) {
          auto it2 = prev(lo.end());
          sum += (long long)it2->first * it2->second;
          hi.insert(*it2);
          lo.erase(it2);
        }
      } else {
        auto it2 = lo.find({f, num});
        if (it2 != lo.end()) {
          lo.erase(it2);
        }
      }
    };

    const int n = nums.size();
    vector<long long> res;
    for (int i = 0; i < n; ++i) {
      if (i >= k) {
        res.emplace_back(sum);

        const int num = nums[i - k];
        remove(freq[num], num);
        --freq[num];
        add(freq[num], num);
      }

      const int num = nums[i];
      remove(freq[num], num);
      ++freq[num];
      add(freq[num], num);
    }

    res.emplace_back(sum);
    return res;
  }
};
