/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-days-spent-together/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int countDaysTogether(const string& arriveAlice, const string& leaveAlice, const string& arriveBob, const string& leaveBob) {
    array<int, 12> days{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    auto toDay = [&](const string& s) {
      int m, d;
      sscanf(s.c_str(), "%d-%d", &m, &d);
      return accumulate(days.begin(), days.begin() + m - 1, 0) + d;
    };

    return max(0,
      min(toDay(leaveAlice), toDay(leaveBob))
      - max(toDay(arriveAlice), toDay(arriveBob)) + 1
    );
  }
};
