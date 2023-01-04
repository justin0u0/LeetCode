/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
 * Runtime: 220ms (93.80%)
 * Time Complexity: O(NlogN)
 */

class Solution {
public:
  int minimumRounds(vector<int>& tasks) {
    sort(tasks.begin(), tasks.end());
    tasks.emplace_back(-1);
    int n = tasks.size();

    int answer = 0;
    int c = 1;

    for (int i = 1; i < n; ++i) {
      if (tasks[i] != tasks[i - 1]) {
        if (c == 1) {
          return -1;
        }

        answer += c / 3;
        if (c % 3 != 0) {
          ++answer;
        }
        c = 1;
      } else {
        ++c;
      }
    }
    
    return answer;
  }
};
