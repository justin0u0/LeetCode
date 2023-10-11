/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-flowers-in-full-bloom/
 * Runtime: 173ms (99.64%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    vector<pair<int, int>> fs;
    fs.reserve(flowers.size() * 2);
    for (const auto& f : flowers) {
      fs.emplace_back(pair{f[0], 1});
      fs.emplace_back(pair{f[1] + 1, -1});
    }
    sort(fs.begin(), fs.end());

    const int n = people.size();
    vector<pair<int, int>> ps(n);
    for (int i = 0; i < n; ++i) {
      ps[i] = {people[i], i};
    }
    sort(ps.begin(), ps.end());

    auto it = fs.begin();
    int tot = 0;
    vector<int> answer(n);
    for (const auto& p : ps) {
      while (it != fs.end() && it->first <= p.first) {
        tot += it->second;
        ++it;
      }
      answer[p.second] = tot;
    }
    return answer;
  }
};
