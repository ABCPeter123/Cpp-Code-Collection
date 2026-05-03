// g++ -std=c++23 -O2 -Wall -Wextra -Wshadow -DLOCAL A.cpp -o A.exe
// g++ -std=c++23 -O0 -DLOCAL A.cpp -o A.exe
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define ff first
#define ss second
 
const int INF = 1e9;
const ll LINF = 4e18;
const ll MOD = 676767677;
 
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
 
        vector<vector<int>> edges(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            edges[u].pb(v);
            edges[v].pb(u);
        }
 
        vector<int> parent(n + 1, 0);
        vector<int> order;
        stack<int> s;
        s.push(1);
        parent[1] = -1;
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            order.pb(cur);
            
            for (int v : edges[cur]) {
                if (v == parent[cur]) continue;
                parent[v] = cur;
                s.push(v);
            }
        }
 
        vector<int> leaves(n + 1, 0);
        int total = 0;
        for (int i = 1; i <= n; i++) {
            if (sz(edges[i]) == 1) {
                leaves[i] = 1;
                total++;
            }
        }
 
        for (int i = sz(order) - 1; i >= 0; i--) {
            int cur = order[i];
            
            for (int v : edges[cur]) {
                if (parent[v] == cur) {
                    leaves[cur] += leaves[v];
                }
            }
        }
        ll base = 0;
        for (int i = 2; i <= n; i++) {
            if (leaves[i] % 2 == 1) {
                base++;
            }
        }
        if (total % 2 == 0) {
            cout << base << "\n";
            continue;
        }
 
        vector<int> score(n + 1, 0);
        int best = -INF;
        for (int v : order) {
            if (v != 1) {
                int w;
                if (leaves[v] % 2 == 1) {
                    w = 1;
                } else {
                    w = -1;
                }
 
                score[v] = score[parent[v]] + w;
            }
            if (sz(edges[v]) == 1) {
                best = max(best, score[v]);
            }
        }
 
        cout << base - best << "\n";
    }
 
    return 0;
}