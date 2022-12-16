/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/implement-queue-using-stacks/
 * Runtime: 0ms (100.00%)
 */

class MyQueue {
private:
  stack<int> in, out;
public:
  MyQueue() {}
  
  void push(int x) {
    in.push(x);
  }
  
  int pop() {
    int res = peek();
    out.pop();
    return res;
  }
  
  int peek() {
    if (!out.empty()) {
      return out.top();
    }
    while (!in.empty()) {
      out.push(in.top());
      in.pop();
    }
    return out.top();
  }
  
  bool empty() {
    return in.empty() && out.empty();
  }
};
