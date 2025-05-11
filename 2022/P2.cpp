#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int x,y,g;
    cin >> x;
    vector<pair<string, string>> same;
    for (int i = 0; i < x; i++) {
        string temp1, temp2;
        cin >> temp1 >> temp2;
        same.push_back(make_pair(temp1, temp2));
    }
    cin >> y;
    vector<pair<string, string>> nsame;
    for (int i = 0; i < y; i++) {
        string temp1, temp2;
        cin >> temp1 >> temp2;
        nsame.push_back(make_pair(temp1, temp2));
    }
    cin >> g;
    unordered_map<string, pair<string, string>> h;
    for (int i = 0; i < g; i++) {
        string temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        h.insert({temp1, make_pair(temp2, temp3)});
        h.insert({temp2, make_pair(temp1, temp3)});
        h.insert({temp3, make_pair(temp1, temp2)});
    }

    int counter = 0;
    for (int i = 0; i < x; i++) {
        pair<string, string> temp = h.at(same[i].first);
        if (same[i].second != temp.first && same[i].second != temp.second) counter++;
    }

    for (int i = 0; i < y; i++) {
        pair<string, string> temp = h.at(nsame[i].first);
        if (nsame[i].second == temp.first || nsame[i].second == temp.second) counter++;
    }

    cout << counter << endl;

}