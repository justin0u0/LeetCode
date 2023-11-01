/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-mode-in-binary-search-tree/
 * Runtime: 11ms (90.70%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<int> findMode(TreeNode* root) {
    vector<int> answer;

    int prev = INT_MIN;
    int freq = 0;
    int maxFreq = 0;
    function<void(TreeNode*)> dfs = [&](TreeNode* n) {
      if (n->left != nullptr) {
        dfs(n->left);
      }
      if (n->val == prev) {
        ++freq;
      } else {
        printf("prev=%d, freq=%d\n", prev, freq);
        if (freq > maxFreq) {
          maxFreq = freq;
          answer.clear();
          answer.emplace_back(prev);
        } else if (freq == maxFreq) {
          answer.emplace_back(prev);
        }
        prev = n->val;
        freq = 1;
      }

      if (n->right != nullptr) {
        dfs(n->right);
      }
    };
    dfs(root);

    if (freq > maxFreq) {
      answer.clear();
      answer.emplace_back(prev);
    } else if (freq == maxFreq) {
      answer.emplace_back(prev);
    }

    return answer;
  }
};
