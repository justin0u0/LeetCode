/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/permutations/
 * Runtime: 0ms (100.00%)
 */

class Solution {
#define USED 100
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> answer;
    
    const int n = nums.size();
    function<void(vector<int>&)> dfs = [&](vector<int>& box) {
      if (box.size() == n) {
        answer.emplace_back(box);
        return;
      }
      for (int i = 0; i < n; ++i) {
        if (nums[i] != USED) {
          box.emplace_back(nums[i]);
          nums[i] = USED;
          dfs(box);
          nums[i] = box.back();
          box.pop_back();
        }
      }
    };

    vector<int> box;
    box.reserve(n);
    dfs(box);

    return answer;
  }
};
