/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/two-best-non-overlapping-events/
 * Runtime: 31ms (99.55%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxTwoEvents(const vector<vector<int>>& events) {
    const int n = events.size();

    vector<pair<int, int>> starts(n);
    vector<pair<int, int>> ends(n);
    for (int i = 0; i < n; ++i) {
      const auto& e = events[i];
      starts[i] = {e[0], e[2]};
      ends[i] = {e[1], e[2]};
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    int j = 0;
    int maxEnds = 0;
    int maxEvents = 0;
    for (int i = 0; i < n; ++i) {
      while (ends[j].first < starts[i].first) {
        maxEnds = max(maxEnds, ends[j].second);
        ++j;
      }
      maxEvents = max(maxEvents, starts[i].second + maxEnds);
    }
    return maxEvents;
  }
};
