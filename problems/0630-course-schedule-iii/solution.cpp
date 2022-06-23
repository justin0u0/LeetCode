/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/course-schedule-iii/
 * Runtime: 274ms
 * Time Complexity: O(NlogN)
 * Description:
 * 	Greedy, schedule course with smaller "lastDay" first.
 *
 * 	Sum up the total duration, if the total duration violate the course "lastDay",
 * 	remove the course with the greatest duration (so the total duration will be
 * 	as small as possible).
 *
 * 	Since "sum" is always smaller than the "lastDay" after each course, we can
 *	ensure that removing the course with the greatest duration will definitely
 *	remains this property.
 */

class Solution {
private:
public:
  int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), [](const vector<int>& lhs, const vector<int>& rhs) -> bool {
      return lhs[1] < rhs[1];
    });

    priority_queue<int> pq;
    int sum = 0;
    int answer = 0;
    for (const vector<int>& course : courses) {
      sum += course[0];
      pq.push(course[0]);
      ++answer;

      if (sum > course[1]) {
        sum -= pq.top();
        pq.pop();
        --answer;
      }
    }

    return answer;
  }
};
