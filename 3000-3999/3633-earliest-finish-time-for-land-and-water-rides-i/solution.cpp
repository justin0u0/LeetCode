/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int earliestFinishTime(const vector<int>& landStartTime, const vector<int>& landDuration, const vector<int>& waterStartTime, const vector<int>& waterDuration) {
    int earliest = INT_MAX;

    int landT = INT_MAX;
    for (int i = 0; i < landStartTime.size(); ++i) {
      landT = min(landT, landStartTime[i] + landDuration[i]);
    }
    for (int i = 0; i < waterStartTime.size(); ++i) {
      earliest = min(earliest, max(landT, waterStartTime[i]) + waterDuration[i]);
    }

    int waterT = INT_MAX;
    for (int i = 0; i < waterStartTime.size(); ++i) {
      waterT = min(waterT, waterStartTime[i] + waterDuration[i]);
    }
    for (int i = 0; i < landStartTime.size(); ++i) {
      earliest = min(earliest, max(waterT, landStartTime[i]) + landDuration[i]);
    }
    return earliest;
  }
};
