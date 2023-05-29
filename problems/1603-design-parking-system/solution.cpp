/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/design-parking-system/
 * Runtime: 50ms (97.70%)
 */

class ParkingSystem {
private:
  array<int, 3> left;
public:
  ParkingSystem(int big, int medium, int small) : left({big, medium, small}) {}

  bool addCar(int carType) {
    int& l = left[carType - 1];
    if (l == 0) {
      return false;
    }
    --l;
    return true;
  }
};
