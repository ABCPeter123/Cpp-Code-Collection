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
        vector<int> v(2 * n, 0);
        vector<int> dp(n, -2);
        for (int i = 0; i < 2 * n; i++) {
            int t;
            cin >> t;
            v[i] = t;
            if (dp[t] == -2) dp[t] = -1;
            else dp[t] = i;
        }
        vector<int> save;
        int r = -1;
        int ma = 1;
        for (int i = 0; i < 2 * n; i++) {
            int cur = dp[v[i]];
            if (r == -1) {
                r = cur;
                save.pb(v[i]);
            } else {
                if (r == i + 1) {
                    save.pb(v[i]);
                    sort(all(save));
                    bool temp = false;
                    for (int i = 0; i < sz(save); i++) {
                        if (save[i] != i) {temp = true; ma = max(ma, i); break;}
                    }
                    if (!temp) ma = max(ma, sz(save));
                    save = {};
                    r = -1;
                    i += (sz(save) - 1);
                    continue;
                }
                if (cur == r - 1) {
                    if (cur == i + 1) {
                        save.pb(v[i]);
                        sort(all(save));
                        bool temp = false;
                        for (int i = 0; i < sz(save); i++) {
                            if (save[i] != i) {temp = true; ma = max(ma, i); break;}
                        }
                        if (!temp) ma = max(ma, sz(save));
                        save = {};
                        r = -1;
                        i += sz(save);
                        continue;
                    }
                    r--;
                    save.pb(v[i]);
                } else {
                    r = -1;
                    save = {};
                    i--;
                }
            }
        }
        cout << ma << "\n";
    }
 
    return 0;
}