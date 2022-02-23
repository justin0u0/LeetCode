/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/clone-graph/
 * Runtime: 0ms
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
  Node* newNodes[110] = {nullptr};
public:
  Node* cloneGraph(Node* u) {
    if (u == nullptr)
      return nullptr;

    Node* newNode = new Node(u->val);
    newNodes[u->val] = newNode;

    for (Node* v : u->neighbors) {
      if (newNodes[v->val] == nullptr) {
        cloneGraph(v);
      }

      newNode->neighbors.emplace_back(newNodes[v->val]);
    }

    return newNode;
  }
};

