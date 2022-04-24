/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/design-underground-system/
 * Runtime: 160ms
 */

class UndergroundSystem {
private:
  unordered_map<int, pair<string, int>> inflight;
  unordered_map<string, pair<long long, int>> mp;
public:
  UndergroundSystem() {
  }

  void checkIn(int id, string stationName, int t) {
    inflight.emplace(id, make_pair(stationName, t));
  }

  void checkOut(int id, string stationName, int t) {
    unordered_map<int, pair<string, int>>::iterator it = inflight.find(id);
    string s = it->second.first + "." + stationName;
    long long d = t - it->second.second;
    inflight.erase(it);

    unordered_map<string, pair<long long, int>>::iterator it2 = mp.find(s);
    if (it2 == mp.end()) {
      mp.emplace(s, make_pair(d, 1));
    } else {
      it2->second.first += d;
      it2->second.second++;
    }
  }

  double getAverageTime(string startStation, string endStation) {
    string s = startStation + "." + endStation;
    pair<long long, int>& p = mp.at(s);

    return 1.0 * p.first / p.second;
  }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
