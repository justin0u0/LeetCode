/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-town-judge/
 */

class Solution {
public:
  int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> indeg(n + 1, 0);
    vector<int> outdeg(n + 1, 0);
    for (vector<int>& pair : trust) {
      ++outdeg[pair[0]];
      ++indeg[pair[1]];
    }

    int judge = -1;
    for (int i = 1; i <= n; i++) {
      if (indeg[i] == n - 1 && outdeg[i] == 0) {
        if (judge != -1) {
          return -1;
        }
        
        judge = i;
      }
    }
    
    return judge;
  }
};

