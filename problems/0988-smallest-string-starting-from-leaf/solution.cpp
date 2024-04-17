/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/smallest-string-starting-from-leaf/
 * Runtime: 4ms (91.27%)
 */

class Solution {
public:
  string smallestFromLeaf(TreeNode* root) {
    string answer = "";
    string s = "";

    function<void(TreeNode*)> dfs = [&](TreeNode* root) {
      s.append(1, root->val + 'a');

      if (!root->left && !root->right) {
        string orig = s;
        reverse(s.begin(), s.end());
        if (answer == "" || answer.compare(s) > 0) {
          answer = s;
        }
        s = orig;
      }
      if (root->left) {
        dfs(root->left);
      }
      if (root->right) {
        dfs(root->right);
      }

      s.pop_back();
    };
    dfs(root);

    return answer;
  }
};
