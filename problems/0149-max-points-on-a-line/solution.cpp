/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/max-points-on-a-line/
 * Runtime: 48ms (84.21%)
 */

class Solution {
private:
  class Slope {
  private:
    int dx;
    int dy;
  public:
    Slope(int dx, int dy) : dx(dx), dy(dy) {}

    bool operator==(const Slope& rhs) const {
      return dx * rhs.dy == dy * rhs.dx;
    }

    class Hash {
    public:
      size_t operator()(const Slope& s) const {
        int g = gcd(s.dx, s.dy);
        return ((abs(s.dx) / g) << 16) + abs(s.dy) / g;
      }
    };
  };
public:
  int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 2) {
      return n;
    }

    int answer = 2;
    for (int i = 0; i < n; ++i) {
      const vector<int>& x = points[i];
      unordered_map<Slope, int, Slope::Hash> slopes;
      for (int j = 0; j < n; ++j) {
        const vector<int>& y = points[j];
        if (i == j) {
          continue;
        }

        Slope s(y[0] - x[0], y[1] - x[1]);
        auto it = slopes.find(s);
        if (it == slopes.end()) {
          slopes.emplace(s, 2);
        } else {
          answer = max(answer, ++slopes.at(s));
        }
      }
    }
    return answer;
  }
};
