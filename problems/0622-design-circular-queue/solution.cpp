/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/design-circular-queue/
 * Runtime: 24ms (93.43%)
 */

class MyCircularQueue {
private:
  size_t cap;
  size_t size;

  int* buf;
  int head;
  int tail;
public:
  MyCircularQueue(int k) : cap(k), size(0), buf(new int[k]), head(0), tail(0) {}

  ~MyCircularQueue() {
    delete[] buf;
  }

  bool enQueue(int value) {
    if (size == cap) {
      return false;
    }

    buf[tail] = value;
    tail = (tail + 1) % cap;
    ++size;
    return true;
  }

  bool deQueue() {
    if (size == 0) {
      return false;
    }

    head = (head + 1) % cap;
    --size;
    return true;
  }

  int Front() {
    if (size == 0) {
      return -1;
    }

    return buf[head];
  }

  int Rear() {
    if (size == 0) {
      return -1;
    }

    return buf[(tail + cap - 1) % cap];
  }

  bool isEmpty() {
    return size == 0;
  }

  bool isFull() {
    return size == cap;
  }
};
