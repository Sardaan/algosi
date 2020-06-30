#include <iostream>
#include <map>
#include <set>

using namespace std;

map<string, long long> money;
map<string, string> location;
map<string, long long> cityFortune;
set<pair<long long, string>> cities;
map<string, int> answer;


void update_city_fortunes(const string& city, long long money) {
    if (cityFortune.count(city)) {
        cities.erase({cityFortune[city], city});
    }
    cityFortune[city] += money;
    cities.emplace(cityFortune[city], city);
}

void update_answer(int prev_moment, int next_moment) {
    auto biggest = cities.rbegin();
    if (cities.size() > 1 and next(biggest)->first == biggest->first) {
        return ; }
    answer[biggest->second] += next_moment - prev_moment;
}
int main () {
    int n, m, k;
    cin >> n;
    string name, city;
    for (int i = 0; i < n; ++i) {
        long long fortune;
        cin >> name >> city >> fortune;
        money[name] = fortune;
        location[name] = city;
        update_city_fortunes(city, fortune);
    }
    cin >> m >> k;
    int dayCount = 0;

    for (int i = 1; i <= k; ++i) {
        int day;
        cin >>day >> name >> city;
        if (day != dayCount)
            update_answer(dayCount, day);
        update_city_fortunes(location[name], -money[name]);
        update_city_fortunes(city, money[name]);
        location[name] = city;
        dayCount = day;
    }
    update_answer(dayCount, m);

    for (auto ans: answer) {
        cout << ans.first <<" "<< ans.second << endl;
    }
    return 0;
}