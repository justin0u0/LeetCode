/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/seat-reservation-manager/
 * Runtime: 238ms (99.57%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class SeatManager {
private:
  priority_queue<int, vector<int>, greater<int>> pq;
public:
  SeatManager(int n) {
    for (int i = 1; i <= n; ++i) {
      pq.push(i);
    }
  }
  
  int reserve() {
    int res = pq.top();
    pq.pop();
    return res;
  }
  
  void unreserve(int seatNumber) {
    pq.push(seatNumber);
  }
};
