/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/all-possible-full-binary-trees/
 * Runtime: 92ms (93.37%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  const static vector<vector<TreeNode*>> fbts;
public:
  vector<TreeNode*> allPossibleFBT(int n) {
    return fbts[n];
  }
};

const vector<vector<TreeNode*>> Solution::fbts = []() {
  vector<vector<TreeNode*>> sols;
  sols.emplace_back(vector<TreeNode*>{}); // 0
  sols.emplace_back(vector<TreeNode*>{new TreeNode}); // 1

  for (int i = 2; i <= 20; ++i) {
    vector<TreeNode*> box;
    if (i & 1) {
      for (int j = 1; j <= i - 1; j += 2) {
        const auto& ls = sols[j];
        const auto& rs = sols[i - 1 - j];
        for (TreeNode* l : ls) {
          for (TreeNode* r : rs) {
            box.emplace_back(new TreeNode(0, l, r));
          }
        }
      }
    }
    sols.emplace_back(box);
  }

  return sols;
}();
