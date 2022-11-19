/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/erect-the-fence/
 * Runtime: 38ms (100.00%)
 */

class Solution {
private:
  class Point {
  public:
    int x, y;

    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
    Point(const Point& p) : x(p.x), y(p.y) {}
    Point(const vector<int>& p) : x(p[0]), y(p[1]) {}

    bool operator==(const Point& rhs) const {
      return x == rhs.x && y == rhs.y;
    }

    bool operator<(const Point& rhs) const {
      return x < rhs.x || (x == rhs.x && y < rhs.y);
    }

    Point operator-(const Point& rhs) const {
      return Point(x - rhs.x, y - rhs.y);
    }

    static int cross(const Point& lhs, const Point& rhs) {
      return lhs.x * rhs.y - lhs.y * rhs.x;
    }

    class Hash {
    public:
      size_t operator()(const Point& p) const {
        return (p.x<<16) + p.y;
      }
    };
  };
public:
  vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
    int n = trees.size();
    if (n <= 3) {
      return trees;
    }

    vector<Point> points(trees.size());
    copy(trees.begin(), trees.end(), points.begin());
    sort(points.begin(), points.end());
    vector<Point> ch(trees.size() * 2);

    int x = 0;
    for (int i = 0; i < n; ++i) {
      while (x > 1 && Point::cross(points[i] - ch[x - 2], ch[x - 1] - ch[x - 2]) < 0) {
        --x;
      }
      ch[x++] = points[i];
    }

    int y = x;
    for (int i = n - 2; i >= 0; --i) {
      while (y > x && Point::cross(points[i] - ch[y - 2], ch[y - 1] - ch[y - 2]) < 0) {
        --y;
      }
      ch[y++] = points[i];
    }

    unordered_set<Point, Point::Hash> s;
    for (int i = 0; i < y; ++i) {
      s.emplace(ch[i]);
    }

    vector<vector<int>> answer;
    answer.reserve(s.size());
    for (const Point& p : s) {
      answer.emplace_back(vector<int>{p.x, p.y});
    }

    return answer;
  }
};
