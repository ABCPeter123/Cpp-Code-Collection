#include <bits/stdc++.h>
using namespace std;
#define MAX 9223372036854775807
#define ll long long

struct comp {
    bool operator()(tuple<int, int, int> a, tuple<int, int, int> b) {
        return get<1>(a) > get<1>(b);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<pair<ll, ll>> vertex(n, make_pair(MAX, MAX)); // l, c
    vector<vector<tuple<int, int, int>>> edge(n, vector<tuple<int, int, int>>());

    for (int i = 0; i < m; i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        edge[b - 1].push_back(make_tuple(a - 1,c,d));
        edge[a - 1].push_back(make_tuple(b - 1,c,d));
    }

    function<void()> dijkstra = [&] () {
        priority_queue<tuple<int, ll, ll>, vector<tuple<int, ll, ll>>, comp> pq;
        ll cost = 0;
        for (int i = 0; i < n; i++) {
            if (vertex[i].first != MAX) continue;
            pq.push(make_tuple(i, 0, 0));

            while (!pq.empty()) {
                int v = get<0>(pq.top()), l = get<1>(pq.top()), c = get<2>(pq.top());
                pq.pop();
                for (auto j : edge[v]) {
                    if (l + get<1>(j) < vertex[get<0>(j)].first) {
                        vertex[get<0>(j)].first = l + get<1>(j);
                        if (vertex[get<0>(j)].second == MAX) cost += c + get<2>(j);
                        else cost += c + get<2>(j) - vertex[get<0>(j)].second;
                        vertex[get<0>(j)].second = c + get<2>(j);
                        pq.push(make_tuple(get<0>(j), vertex[get<0>(j)].first, vertex[get<0>(j)].second));
                    } else if (l + get<1>(j) == vertex[get<0>(j)].first && c + get<2>(j) < vertex[get<0>(j)].second) {
                        if (vertex[get<0>(j)].second == MAX) cost += c + get<2>(j);
                        else cost += c + get<2>(j) - vertex[get<0>(j)].second;
                    }
                }
            }
        }
        cout << cost;
    };

    dijkstra();
}