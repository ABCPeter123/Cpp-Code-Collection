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

const int INF = 1e9 + 1;
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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> robots(n, 0);
        vector<int> spikes(m, 0);
        for (int i = 0; i < n; i++) {
            cin >> robots[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> spikes[i];
        }
        string inst;
        cin >> inst;
        sort(all(spikes));
        vector<pair<int, int>> R;
        vector<pair<int, int>> L;

        for (int i = 0; i < n; i++) {
            auto r = upper_bound(all(spikes), robots[i]);
            auto l = lower_bound(all(spikes), robots[i]);
            if (r != spikes.end()) {
                int dist = *r - robots[i];
                if (dist <= k) R.pb({dist, i});
            }
            if (l != spikes.begin()) {
                --l;
                int dist = robots[i] - *l;
                if (dist <= k) L.pb({dist, i});
            }
        }

        sort(all(R));
        sort(all(L));
        vector<bool> alive(n, true);

        int d = 0;
        int cnt = n;
        int rm = 0;
        int lm = 0;

        int pr = 0;
        int pl = 0;
        for (char i : inst) {
            if (i == 'R') {
                d++;
            } else d--;
            int ad = abs(d);
            if (d > 0) {
                if (ad <= rm) {cout << cnt << " "; continue;}
                rm = ad;
                while (pr < sz(R) && R[pr].ff <= rm) {
                    int id = R[pr].ss;
                    if (alive[id]) {
                        alive[id] = false;
                        cnt--;
                    }
                    pr++;
                }
                cout << cnt << " ";
            } else if (d < 0) {
                if (ad <= lm) {cout << cnt << " "; continue;}
                lm = ad;
                while (pl < sz(L) && L[pl].ff <= lm) {
                    int id = L[pl].ss;
                    if (alive[id]) {
                        alive[id] = false;
                        cnt--;
                    }
                    pl++;
                }
                cout << cnt << " ";
            } else {
                cout << cnt << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}