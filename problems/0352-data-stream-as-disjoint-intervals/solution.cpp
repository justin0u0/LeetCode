/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/data-stream-as-disjoint-intervals/
 * Runtime: 52ms (95.69%)
 */

class SummaryRanges {
private:
  set<pair<int, int>> intervals;
public:
  SummaryRanges() {
  }

  void addNum(int value) {
    pair<int, int> target{value, value};
    if (intervals.empty()) {
      intervals.emplace(target);
      return;
    }

    bool ok = true;
    auto rit = intervals.upper_bound(target);
    if (rit != intervals.begin()) {
      auto lit = prev(rit);
      if (lit->second == value - 1) {
        target.first = lit->first;
        intervals.erase(lit);
      } else if (lit->second >= value) {
        ok = false;
      }
    }
    if (rit != intervals.end()) {
      if (rit->first == value + 1) {
        target.second = rit->second;
        intervals.erase(rit);
      } else if (rit->first <= value) {
        ok = false;
      }
    }

    if (ok) {
      intervals.emplace(target);
    }
  }

  vector<vector<int>> getIntervals() {
    vector<vector<int>> result;
    result.reserve(intervals.size());
    for (const auto& [l, r] : intervals) {
      result.emplace_back(vector<int>{l, r});
    }
    return result;
  }
};
