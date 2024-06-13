/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());
    int answer = 0;
    for (int i = 0; i < seats.size(); ++i) {
      answer += abs(seats[i] - students[i]);
    }
    return answer;
  }
};
