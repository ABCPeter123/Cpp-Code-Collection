#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cerr << #x << " = " << x << "\n";

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll c;
    ll t = 0;
    vector<pair<ll, char>> v;

    string temp;
    getline(cin, temp);
    cin >> c;

    for (char i : temp) {
        if ('a' <= i && i <= 'z') {
            if (v.size() != 0) t += v[v.size() - 1].first;
            v.push_back(make_pair(0, i));
        } else {
            v[v.size() - 1].first *= 10;
            v[v.size() - 1].first += (i - '0');
        }
    }
    t += v[v.size() - 1].first;
    c = c % t;

    for (auto i : v) {
        if (c < i.first) {
            cout << i.second;
            break;
        }
        c -= i.first;
    }
}
