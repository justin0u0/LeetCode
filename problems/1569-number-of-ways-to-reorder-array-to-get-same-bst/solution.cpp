/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/
 * Runtime: 152ms (76.82%)
 */

class Solution {
private:
  int c[1000][1000];

  const int mod = 1e9 + 7;

  int C(int n, int r) {
    if (r == 0 || n == r) {
      return 1;
    }

    int& res = c[n][r];
    if (res != 0) {
      return res;
    }

    res = C(n - 1, r) + C(n - 1, r - 1);
    if (res >= mod) {
      res -= mod;
    }
    return res;
  }

  class Node {
  public:
    int val;
    Node* left;
    Node* right;

    Node(int val) : val(val), left(nullptr), right(nullptr) {}
  };

  pair<int, int> solve(Node* u) {
    if (u == nullptr) {
      return {0, 1};
    }

    auto [lc, lw] = solve(u->left);
    auto [rc, rw] = solve(u->right);

    return {
      1 + lc + rc,
      (1LL * C(lc + rc, lc) * lw % mod) * rw % mod
    };
  }
public:
  int numOfWays(vector<int>& nums) {
    int n = nums.size();
    Node* root = new Node(nums[0]);
    for (int i = 1; i < n; ++i) {
      int val = nums[i];
      Node* cur = root;
      while (true) {
        if (cur->val > val) {
          if (cur->left == nullptr) {
            cur->left = new Node(val);
            break;
          }
          cur = cur->left;
        } else {
          if (cur->right == nullptr) {
            cur->right = new Node(val);
            break;
          }
          cur = cur->right;
        }
      }
    }

    return solve(root).second - 1;
  }
};
