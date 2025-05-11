#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cerr << #x << " = " << x << "\n";

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, Q;
    ll p = 0;
    cin >> N >> M >> Q;
    vector<pair<int, int>> pen(N, make_pair(0, 0));
    vector<multiset<int, greater<int>>> color;
    multiset<int> one;
    multiset<int, greater<int>> two;

    for (int i = 0; i < M; i++) color.push_back({0});


    // input
    for (int i = 0; i < N; i++) {
        cin >> pen[i].first >> pen[i].second;
        pen[i].first--;
        color[pen[i].first].insert(pen[i].second);
    }
    
    // for (int i = 0; i < N; i++) cout << pen[i].first << " " << pen[i].second << endl;

    // for (auto j : color) {
    //     for (auto k : j) cout << k << " ";
    //     cout << "\n";
    // }


    // setup O(log(M)) retrieval
    for (int i = 0; i < M; i++) {
        one.insert(*color[i].begin());
        p += *color[i].begin();
        two.insert(*(++color[i].begin()));
    }

    // for (auto j : one) cout << j << " ";
    // cout << "\n";
    // for (auto j : two) cout << j << " ";
    // cout << "\n";

    vector<ll> ans;
    if (*two.begin() > *one.begin()) {
        p -= *one.begin(); 
        p += *two.begin();
        ans.push_back(p);
        p += *one.begin(); 
        p -= *two.begin();
    } else ans.push_back(p);

    for (int i = 0; i < Q; i++) {
        int dump, pe, tc, pr, c;
        cin >> dump >> pe >> tc;
        int p1, p2;
        if (dump == 2) {
            pe--;
            c = pen[pe].first;
            pr = pen[pe].second;

            p1 = *color[c].begin();
            p2 = *(++color[c].begin());
            two.erase(two.find(p2));
            one.erase(one.find(p1));

            color[c].erase(color[c].find(pr));
            color[c].insert(tc);

            p1 = *color[c].begin();
            p2 = *(++color[c].begin());
            two.insert(p2);
            one.insert(p1);

            if (*two.begin() > *one.begin()) {
                p -= *one.begin(); 
                p += *two.begin();
                ans.push_back(p);
                p += *one.begin(); 
                p -= *two.begin();
            } else ans.push_back(p);
            pen[pe] = make_pair(c, tc);
        } else {
            pe--;
            c = pen[pe].first;
            tc--;
            pr = pen[pe].second;
            p1 = *color[c].begin();
            p2 = *(++color[c].begin());
            two.erase(two.find(p2));
            one.erase(one.find(p1));

            color[c].erase(color[c].find(pr));

            p1 = *color[c].begin();
            p2 = *(++color[c].begin());
            two.insert(p2);
            one.insert(p1);

            p1 = *color[tc].begin();
            p2 = *(++color[tc].begin());
            two.erase(two.find(p2));
            one.erase(one.find(p1));

            color[tc].insert(pr);

            p1 = *color[tc].begin();
            p2 = *(++color[tc].begin());
            two.insert(p2);
            one.insert(p1);

            if (*two.begin() > *one.begin()) {
                p -= *one.begin(); 
                p += *two.begin();
                ans.push_back(p);
                p += *one.begin(); 
                p -= *two.begin();
            } else ans.push_back(p);
            pen[pe] = make_pair(tc, pr);
        }
    }

    for (auto i : ans) cout << i << "\n";

}
