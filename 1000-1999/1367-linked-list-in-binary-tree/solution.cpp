/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/linked-list-in-binary-tree/
 * Runtime: 18ms (92.93%)
 */

class Solution {
public:
  bool isSubPath(ListNode* head, TreeNode* root) {
    vector<int> list{head->val};
    vector<int> failure{0};
    int j = 0;
    for (ListNode* cur = head->next; cur != nullptr; cur = cur->next) {
      list.emplace_back(cur->val);
      while (j != 0 && list[j] != cur->val) {
        j = failure[j - 1];
      }
      if (list[j] == cur->val) {
        ++j;
      }
      failure.emplace_back(j);
    }

    const int n = list.size();

    vector<int> path;
    function<bool(TreeNode*, int)> dfs = [&](TreeNode* t, int j) {
      path.emplace_back(t->val);
      while (j != 0 && list[j] != t->val) {
        j = failure[j - 1];
      }
      if (list[j] == t->val) {
        ++j;
      }
      if (j == n) {
        return true;
      }

      if (t->left != nullptr && dfs(t->left, j)) {
        return true;
      }
      if (t->right != nullptr && dfs(t->right, j)) {
        return true;
      }

      path.pop_back();
      return false;
    };
    return dfs(root, 0);
  }
};
