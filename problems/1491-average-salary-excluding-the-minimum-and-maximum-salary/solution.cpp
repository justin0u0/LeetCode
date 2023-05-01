/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  double average(vector<int>& salary) {
    int sum = 0;
    int minSalary = salary[0];
    int maxSalary = minSalary;
    for (int s : salary) {
      minSalary = min(minSalary, s);
      maxSalary = max(maxSalary, s);
      sum += s;
    }

    return 1.0 * (sum - minSalary - maxSalary) / ((int)(salary.size()) - 2);
  }
};
