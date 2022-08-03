/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/my-calendar-i/
 * Runtime: 88ms
 * Time Complexity: O(NlogN) where N is the number of calls
 * Description
 *  Check the books with the end time > the current start time, since those books with the end
 *  <= the current start time is not possible to overlap. Also, only need to check the books who
 *  has the smallest (end, start) pair matching the above condition. Since if some end time is
 *  already <= the current end time, an overlap occurred. Else, all the end time > the current
 *  end time, then if some start time < the current end time, an overlap occurred.
 */

class MyCalendar {
private:
  set<pair<int, int>> box; // (end, start)
public:
  MyCalendar() {}

  bool book(int start, int end) {
    set<pair<int, int>>::iterator it = box.lower_bound(pair{start + 1, 0});
    if (it != box.end() && (it->first <= end || it->second < end)) {
      return false;
    }
    box.emplace(pair{end, start});
    return true;
  }
};
