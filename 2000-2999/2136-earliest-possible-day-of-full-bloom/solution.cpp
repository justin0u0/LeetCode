/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/earliest-possible-day-of-full-bloom/
 * Runtime: 287ms (100.00%)
 */

class Solution {
public:
  int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    int n = plantTime.size();
    vector<pair<int, int>> times(n);
    for (int i = 0; i < n; ++i) {
      times[i] = pair{growTime[i], plantTime[i]};
    }
    sort(times.begin(), times.end());

    int answer = 0;
    for (const auto& t : times) {
      answer = max(answer, t.first) + t.second;
    }
    return answer;
  }
};
