/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/
 * Runtime: 4ms (60.00%)
 */

class Solution {
public:
  int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    startTime.emplace_back(eventTime);
    endTime.emplace_back(eventTime);
    const int n = startTime.size();

    queue<int> q;
    int tot = 0;
    int free = 0;
    int last = 0;
    for (int i = 0; i < n; ++i) {
      const int t = startTime[i] - last;
      last = endTime[i];
      tot += t;
      q.push(t);
      free = max(free, tot);
      if (q.size() > k) {
        tot -= q.front();
        q.pop();
      }
    }
    return free;
  }
};
