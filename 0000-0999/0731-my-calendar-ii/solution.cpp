/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/my-calendar-ii/
 * Runtime: 111ms (80.81%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class MyCalendarTwo {
private:
  map<int, int> sweepline;
public:
  MyCalendarTwo() {}
  
  bool book(int start, int end) {
    ++sweepline[start];
    --sweepline[end];

    int count = 0;
    for (auto [x, c] : sweepline) {
      count += c;
      if (count > 2) {
        if (--sweepline[start] == 0) {
          sweepline.erase(start);
        }
        if (++sweepline[end] == 0) {
          sweepline.erase(end);
        }
        return false;
      }
    }

    return true;
  }
};
