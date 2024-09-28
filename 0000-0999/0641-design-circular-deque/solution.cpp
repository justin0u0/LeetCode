/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/design-circular-deque/
 * Runtime: 19ms (71.33%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class MyCircularDeque {
private:
  vector<int> deq;
  int head;
  int tail;
  int size;
  const int cap;

  inline void decr(int& x) {
    if (--x < 0) {
      x = cap - 1;
    }
  }

  inline void incr(int& x) {
    if (++x >= cap) {
      x = 0;
    }
  }
public:
  MyCircularDeque(int k) : deq(k), head(0), tail(k - 1), size(0), cap(k) {}
  
  bool insertFront(int value) {
    if (isFull()) {
      return false;
    }
    decr(head);
    deq[head] = value;
    ++size;
    return true;
  }
  
  bool insertLast(int value) {
    if (isFull()) {
      return false;
    }
    incr(tail);
    deq[tail] = value;
    ++size;
    return true;
  }
  
  bool deleteFront() {
    if (isEmpty()) {
      return false;
    }
    incr(head);
    --size;
    return true;
  }
  
  bool deleteLast() {
    if (isEmpty()) {
      return false;
    }
    decr(tail);
    --size;
    return true;
  }
  
  int getFront() {
    if (isEmpty()) {
      return -1;
    }
    return deq[head];
  }
  
  int getRear() {
    if (isEmpty()) {
      return -1;
    }
    return deq[tail];
  }
  
  bool isEmpty() {
    return size == 0;
  }
  
  bool isFull() {
    return size == deq.size();
  }
};
