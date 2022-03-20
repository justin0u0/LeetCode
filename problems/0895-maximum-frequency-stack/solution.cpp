/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-frequency-stack/
 * Runtime: 180ms
 */

class FreqStack {
private:
public:
  unordered_map<int, int> freq;
  unordered_map<int, stack<int>*> data;
  int cur;

  FreqStack() : cur(0) {
  }

  void push(int val) {
    int f = ++freq[val];
    if (f > cur) {
      cur = f;
    }

    unordered_map<int, stack<int>*>::iterator it = data.find(f);
    stack<int>* s;
    if (it == data.end()) {
      s = new stack<int>;
      data.emplace(f, s);
    } else {
      s = it->second;
    }

    s->push(val);
  }

  int pop() {
    stack<int>* s = data.at(cur);
    int val = s->top();
    s->pop();

    if (s->empty()) {
      --cur;
    }

    --freq[val];

    return val;
  }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
