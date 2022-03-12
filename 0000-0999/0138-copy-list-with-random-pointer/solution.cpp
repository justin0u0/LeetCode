/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/copy-list-with-random-pointer/
 * Runtime: 13ms
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> m;

    Node* dummy = new Node(0);
    Node* dummyHead = dummy;
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
      Node* newNode = new Node(cur->val);

      m[cur] = newNode;
      dummy->next = newNode;

      dummy = dummy->next;
    }

    for (Node* cur = dummyHead->next; cur != nullptr; cur = cur->next) {
      cur->random = m[head->random];
      head = head->next;
    }

    return dummyHead->next;
  }
};
