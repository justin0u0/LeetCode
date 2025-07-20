/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/delete-duplicate-folders-in-system/
 * Runtime: 154ms (95.77%)
 */

class Solution {
private:
  class TreeNode {
  public:
    map<string, TreeNode*> m;
    const string& name;
    bool marked;

    TreeNode(const string& name) : name(name), marked(false) {}
  };
public:
  vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
    const string& rt = "/";
    TreeNode* root = new TreeNode(rt);

    for (const auto& path : paths) {
      TreeNode* cur = root;
      for (const auto& s : path) {
        auto it = cur->m.find(s);
        if (it == cur->m.end()) {
          TreeNode* n = new TreeNode(s);
          cur->m.emplace(s, n);
          cur = n;
        } else {
          cur = it->second;
        }
      }
    }

    unordered_map<string, TreeNode*> marker;

    function<string(TreeNode*)> mark = [&](TreeNode* n) {
      if (n->m.empty()) {
        return n->name;
      }

      string sub = "";
      for (const auto [_, v] : n->m) {
        sub += mark(v);
        sub += ';';
      }

      auto it = marker.find(sub);
      if (it != marker.end()) {
        it->second->marked = true;
        n->marked = true;
      } else {
        marker.emplace(sub, n);
      }
      return n->name + ";" + sub;
    };
    mark(root);

    vector<vector<string>> res;
    vector<string> path;
    
    function<void(TreeNode*)> scan = [&](TreeNode* n) {
      if (n->marked) {
        return;
      }

      if (n->name != rt) {
        path.emplace_back(n->name);
        res.emplace_back(path);
      }
      if (n->m.empty()) {
        path.pop_back();
        return;
      }

      for (const auto [_, v] : n->m) {
        scan(v);
      }

      if (n->name != rt) {
        path.pop_back();
      }
    };
    scan(root);

    return res;
  }
};
