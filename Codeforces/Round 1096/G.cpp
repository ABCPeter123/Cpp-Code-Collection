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
 
struct Fenwick {
    int n;
    vector<ll> bit;
    Fenwick() {}
    Fenwick(int n) { init(n); }
 
    void init(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }
 
    void add(int idx, ll delta) {
        idx++;
        while (idx <= n) {
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }
 
    ll sumPrefix(int idx) {
        idx++;
        ll res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }
 
    ll sumRange(int l, int r) {
        if (l > r) return 0;
        return sumPrefix(r) - (l ? sumPrefix(l - 1) : 0);
    }
};
 
vector<ll> vals;
 
int get_id(ll x) {
    return int(lower_bound(all(vals), x) - vals.begin());
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> pref(n + 1, 0);
        int cnt = 0;
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            int temp;
            cin >> temp;
            if (cnt % 2 == 0) {
                sum += temp;
            } else {
                sum -= temp;
            }
            cnt = (cnt + 1) % 2;
            pref[i] = sum;
        }
        vals = pref;
        sort(all(vals));
        vals.erase(unique(all(vals)), vals.end());
 
        ll ans = 0;
        Fenwick even(sz(vals)), odd(sz(vals));
        even.add(get_id(pref[0]), 1);
 
        for (int i = 1; i <= n; i++) {
            int id = get_id(pref[i]);
 
            if (i % 2 == 1) {
                ans += even.sumPrefix(id - 1);
                odd.add(id, 1);
            } else {
                ans += odd.sumPrefix(sz(vals) - 1) - odd.sumPrefix(id);
                even.add(id, 1);
            }
        }
        cout << ans << "\n";
    }
 
    return 0;
}