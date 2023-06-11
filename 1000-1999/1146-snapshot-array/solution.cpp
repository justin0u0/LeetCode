/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/snapshot-array/
 * Runtime: 351ms (95.80%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class SnapshotArray {
private:
  vector<vector<pair<int, int>>> arrays;
  int version;
public:
  SnapshotArray(int length) :
    arrays(vector<vector<pair<int, int>>>(length, vector<pair<int, int>>(1, {0, 0}))),
    version(0) {}

  void set(int index, int val) {
    auto& arr = arrays[index];
    if (arr.back().first != version) {
      arr.emplace_back(version, val);
    } else {
      arr.back().second = val;
    }
  }

  int snap() {
    return version++;
  }

  int get(int index, int snapId) {
    auto& arr = arrays[index];
    return prev(lower_bound(arr.begin(), arr.end(), pair<int, int>{snapId, INT_MAX}))->second;
  }
};
