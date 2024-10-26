/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/
 * Runtime: 458ms (66.39%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  int depths[100001];
public:
  vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
    memset(depths, 0, sizeof(depths));

    function<int(TreeNode*, int)> dfs = [&](TreeNode* n, int d) {
      if (n == nullptr) {
        return d;
      }

      depths[n->val] = max(dfs(n->left, d + 1), dfs(n->right, d + 1));
      return depths[n->val];
    };
    dfs(root, 0);

    queue<TreeNode*> q;
    q.push(root);
    for (int d = 0; !q.empty(); ++d) {
      int mx1 = d;
      int mx2 = d;
      int sz = q.size();
      while (sz--) {
        TreeNode* n = q.front();
        q.pop();

        const int d = depths[n->val];

        if (d > mx1) {
          mx2 = mx1;
          mx1 = d;
        } else if (d > mx2) {
          mx2 = d;
        }

        q.push(n);
      }

      sz = q.size();
      while (sz--) {
        TreeNode* n = q.front();
        q.pop();

        if (n->left != nullptr) {
          q.push(n->left);
        }
        if (n->right != nullptr) {
          q.push(n->right);
        }

        if (depths[n->val] == mx1) {
          depths[n->val] = mx2;
        } else {
          depths[n->val] = mx1;
        }
      }
    }

    for (int& q : queries) {
      q = depths[q] - 1;
    }
    return queries;
  }
};
