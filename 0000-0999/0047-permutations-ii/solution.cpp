/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/permutations-ii/
 * Runtime: 3ms
 */

class Solution {
private:
  vector<bool> used;

  void dfs(vector<vector<int>>& answer, vector<int>& box, vector<int>& nums) {
    if (box.size() == nums.size()) {
      answer.emplace_back(box);
      return;
    }

    int cur = -0x3f3f3f3f;

    for (int i = 0; i < (int)nums.size(); ++i) {
      if (!used[i] && nums[i] > cur) {
        used[i] = true;
        cur = nums[i];
        box.emplace_back(nums[i]);

        dfs(answer, box, nums);
        used[i] = false;
        box.pop_back();
      }
    }
  }
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    used.resize(nums.size());
    used.clear();

    sort(nums.begin(), nums.end());

    vector<vector<int>> answer;
    vector<int> box;
    box.reserve(nums.size());

    dfs(answer, box, nums);

    return answer;
  }
};
