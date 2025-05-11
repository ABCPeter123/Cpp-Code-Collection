#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cerr << #x << " = " << x << "\n";

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> v(N, vector<pair<int, int>>()); // next position, chill

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a - 1].push_back(make_pair(b - 1, c));
        v[b - 1].push_back(make_pair(a - 1, c));
    }

    vector<ll> c(N, LONG_LONG_MAX);
    
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
    c[0] = 0;
    for (auto i : v[0]) {
        pq.push(make_tuple(i.second, 0, i.first));
    }

    while (!pq.empty()) {
        auto[cost, chill, cur] = pq.top();
        pq.pop();
        cout << cost << " " << chill << " " << cur << endl;
        for (auto i : v[cur]) {
            if (cost + abs(chill - i.second) < c[i.first]) {
                pq.push(make_tuple(cost + abs(chill - i.second), i.second, i.first));
                c[i.first] = cost + abs(chill - i.second);
            }
        }
    }

    cout << c[c.size() - 1];
}
