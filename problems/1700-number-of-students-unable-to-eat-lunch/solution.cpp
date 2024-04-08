/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int countStudents(const vector<int>& students, const vector<int>& sandwiches) {
    const int n = students.size();
    int zeros = count(students.begin(), students.end(), 0);
    int ones = n - zeros;
    for (int i = 0; i < sandwiches.size(); ++i) {
      if (sandwiches[i] == 0) {
        --zeros;
      } else {
        --ones;
      }
      if (zeros < 0 || ones < 0) {
        return n - i;
      }
    }
    return 0;
  }
};
