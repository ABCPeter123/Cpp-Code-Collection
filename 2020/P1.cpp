#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n, make_pair(0, 0));
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    double speed = -1;
    for (int i = 0; i < n - 1; i++) {
        double speedt = (double) (v[i + 1].second - v[i].second) / (v[i + 1].first - v[i].first);
        speedt = abs(speedt);
        speed = max(speed, speedt);
    }

    cout << fixed << setprecision(6) << speed << endl;
}