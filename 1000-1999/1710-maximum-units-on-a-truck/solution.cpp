/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-units-on-a-truck/
 * Runtime: 39ms
 */

class Solution {
public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& lhs, const vector<int>& rhs) -> bool {
      return lhs[1] > rhs[1];
    });

    int answer = 0;
    for (const vector<int>& boxType : boxTypes) {
      int units = min(boxType[0], truckSize);
      answer += units * boxType[1];
      truckSize -= units;
    }

    return answer;
  }
};
