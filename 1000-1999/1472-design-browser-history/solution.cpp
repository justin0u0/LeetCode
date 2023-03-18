/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/design-browser-history/
 * Runtime: 126ms (95.24%)
 */

class BrowserHistory {
private:
  class HistoryNode {
  public:
    string url;
    HistoryNode* next;
    HistoryNode* prev;

    HistoryNode(string url) : url(url), next(nullptr), prev(nullptr) {}
  };

  HistoryNode* root;
  HistoryNode* now;
public:
  BrowserHistory(const string& homepage) : root(new HistoryNode(homepage)), now(root) {}

  void visit(const string& url) {
    HistoryNode* n = new HistoryNode(url);
    n->prev = now;
    now->next = n;
    now = now->next;
  }

  string back(int steps) {
    for (; steps != 0 && now != root; --steps) {
      now = now->prev;
    }
    return now->url;
  }

  string forward(int steps) {
    for (; steps != 0 && now->next != nullptr; --steps) {
      now = now->next;
    }
    return now->url;
  }
};
