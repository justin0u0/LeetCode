/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/meeting-rooms-iii/
 * Runtime: 240ms (99.81%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
typedef pair<long long, int> PLI;
typedef pair<int, long long> PIL;
public:
  int mostBooked(int n, vector<vector<int>>& meetings) {
    priority_queue<PIL, vector<PIL>, greater<PIL>> avail;
    for (int i = 0; i < n; ++i) {
      avail.push({i, 0});
    }

    vector<int> cnt(n, 0);
    priority_queue<PLI, vector<PLI>, greater<PLI>> used;
    sort(meetings.begin(), meetings.end());
    for (const auto& m : meetings) {
      while (avail.empty() || (!used.empty() && used.top().first <= m[0])) {
        avail.push({used.top().second, used.top().first});
        used.pop();
      }
      auto [i, t] = avail.top();
      avail.pop();
      ++cnt[i];
      used.push({max(t, (long long)m[0]) + m[1] - m[0], i});
    }

    return max_element(cnt.begin(), cnt.end()) - cnt.begin();
  }
};

