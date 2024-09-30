/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/design-a-stack-with-increment-operation/
 * Runtime: 20ms (93.14%)
 */

class CustomStack {
private:
  vector<int> incr;
  stack<int> stk;
  int cap;
public:
  CustomStack(int maxSize) : incr(maxSize + 1, 0), cap(maxSize) {}
  
  void push(int x) {
    if (stk.size() >= cap) {
      return;
    }
    stk.push(x);
  }
  
  int pop() {
    if (stk.empty()) {
      return -1;
    }

    const int n = stk.size();
    const int res = stk.top() + incr[n];
    stk.pop();
    incr[n - 1] += incr[n];
    incr[n] = 0;
    return res;
  }
  
  void increment(int k, int val) {
    incr[min(k, (int)stk.size())] += val;
  }
};
