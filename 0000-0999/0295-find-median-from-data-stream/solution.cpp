/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-median-from-data-stream/
 * Runtime: 348ms (94.12%)
 */

class MedianFinder {
private:
  priority_queue<int, vector<int>, less<int>> ql;
  priority_queue<int, vector<int>, greater<int>> qr;
public:
  MedianFinder() {
    ql.push(INT_MIN);
    qr.push(INT_MAX);
  }

  void addNum(int num) {
    if (num < ql.top()) {
      ql.push(num);
      if (ql.size() - qr.size() > 1) {
        qr.push(ql.top());
        ql.pop();
      }
    } else {
      qr.push(num);
      if (qr.size() - ql.size() > 1) {
        ql.push(qr.top());
        qr.pop();
      }
    }
  }

  double findMedian() {
    if (ql.size() > qr.size()) {
      return ql.top();
    }
    if (qr.size() > ql.size()) {
      return qr.top();
    }

    return (ql.top() + qr.top()) / 2.0;
  }
};
