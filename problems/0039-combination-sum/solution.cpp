/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/combination-sum/
 * Runtime: 7ms
 */

class Solution {
private:
  vector<vector<int>> answer;
  
  void dfs(vector<int>& candidates, vector<int>::iterator it, int target, vector<int>& box) {
    if (target == 0) {
      answer.emplace_back(box);
      return;
    }

    if (it == candidates.end()) {
      return;
    }

    if ((*it) <= target) {
      box.emplace_back(*it);
      dfs(candidates, it, target - (*it), box);
      box.pop_back();
    }

    dfs(candidates, it + 1, target, box);
  }
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> box;

    dfs(candidates, candidates.begin(), target, box);

    return answer;
  }
};
