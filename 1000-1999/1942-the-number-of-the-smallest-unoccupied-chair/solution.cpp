/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/
 * Runtime: 92ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int smallestChair(const vector<vector<int>>& times, const int targetFriend) {
    const int n = times.size();

    vector<pair<int, int>> events;
    events.reserve(n << 1);
    for (int i = 0; i < n; ++i) {
      events.push_back({times[i][0], i + 1});
      events.push_back({times[i][1], -i - 1});
    }
    sort(events.begin(), events.end());

    vector<int> numbers(n);

    priority_queue<int, vector<int>, greater<int>> pq;
    int count = 0;
    for (const auto [_, i] : events) {
      if (i < 0) {
        --count;
        pq.push(numbers[-i - 1]);
      } else {
        if (pq.empty()) {
          numbers[i - 1] = count;
        } else {
          numbers[i - 1] = pq.top();
          pq.pop();
        }
        ++count;
      }
    }
    return numbers[targetFriend];
  }
};
