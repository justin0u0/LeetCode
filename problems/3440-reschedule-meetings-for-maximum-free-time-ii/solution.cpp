/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/
 * Runtime: 2ms (97.21%)
 */

class Solution {
public:
  int maxFreeTime(const int eventTime, vector<int>& startTime, vector<int>& endTime) {
    startTime.emplace_back(eventTime);
    endTime.emplace_back(eventTime);

    const int n = startTime.size();

    int slots[3] = {0};

    int last = 0;
    for (int i = 0; i < n; ++i) {
      const int slot = startTime[i] - last;
      last = endTime[i];

      for (int j = 0; j < 3; ++j) {
        if (slot > slots[j]) {
          for (int k = 2; k > j; --k) {
            slots[k] = slots[k - 1];
          }
          slots[j] = slot;
          break;
        }
      }
    }

    last = 0;
    int maxFree = 0;
    for (int i = 0; i < n - 1; ++i) {
      int s1 = startTime[i] - last;
      int s2 = startTime[i + 1] - endTime[i];
      last = endTime[i];
      if (s1 < s2) {
        swap(s1, s2);
      }

      int j = 0;
      if (s1 == slots[0] && s2 == slots[1]) {
        j = 2;
      } else if (s1 == slots[0]) {
        j = 1;
      }

      const int d = endTime[i] - startTime[i];
      if (d <= slots[j]) {
        maxFree = max(maxFree, s1 + s2 + d);
      } else {
        maxFree = max(maxFree, s1 + s2);
      }
    }
    return maxFree;
  }
};
