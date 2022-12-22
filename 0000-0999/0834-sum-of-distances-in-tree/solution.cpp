/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sum-of-distances-in-tree/
 * Runtime: 256ms (96.63%)
 */

class Solution {
private:
  int n;

  struct TreeNode {
  public:
    vector<TreeNode*> childs;
    int sumChilds;  // sum distance to all child nodes
    int numChilds;  // number of childs
    int sumOthers;  // sum distance to all non-child nodes
  };

  void calcChilds(TreeNode* u, TreeNode* pa) {
    u->numChilds = 1;
    for (TreeNode* v : u->childs) {
      if (v == pa) {
        continue;
      }
      calcChilds(v, u);
      u->numChilds += v->numChilds;
      u->sumChilds += v->numChilds + v->sumChilds;
    }
  }

  void calcOthers(TreeNode* u, TreeNode* pa) {
    if (pa != nullptr) {
      int sumNodes = pa->sumOthers + pa->sumChilds - (u->numChilds + u->sumChilds);
      int numNodes = n - u->numChilds;
      u->sumOthers = sumNodes + numNodes;
    }
    for (TreeNode* v : u->childs) {
      if (v == pa) {
        continue;
      }
      calcOthers(v, u);
    }
  }
public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    this->n = n;
    vector<TreeNode> nodes(n);

    for (vector<int>& edge : edges) {
      nodes[edge[0]].childs.emplace_back(&nodes[edge[1]]);
      nodes[edge[1]].childs.emplace_back(&nodes[edge[0]]);
    }

    TreeNode* root = &nodes[0];
    calcChilds(root, nullptr);
    calcOthers(root, nullptr);

    vector<int> answer(n);
    for (int i = 0; i < n; ++i) {
      answer[i] = nodes[i].sumChilds + nodes[i].sumOthers;
    }
    return answer;
  }
};
