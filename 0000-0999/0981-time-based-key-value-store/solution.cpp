/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/time-based-key-value-store/
 * Runtime: 305ms (99.36%)
 */

class TimeMap {
private:
  class Value {
  public:
    int timestamp;
    string value;

    bool operator < (const Value& rhs) const {
      return timestamp < rhs.timestamp;
    }
  };

  unordered_map<string, vector<Value>> m;
public:
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    m[key].emplace_back(Value{timestamp, value});
  }

  string get(string key, int timestamp) {
    auto it = m.find(key);
    if (it == m.end()) {
      return "";
    }

    const vector<Value>& values = it->second;
    auto vit = upper_bound(values.begin(), values.end(), Value{timestamp, ""});
    if (vit == values.begin()) {
      return "";
    }

    return prev(vit)->value;
  }
};

