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
        int n;
        cin >> n;
        n--;
        int total = 0;
        vector<vector<int>> v;
        vector<pair<int, int>> MEX(n + 1, {0, 0});
        unordered_map<int, int> m;
        ll ans = 0;
        for (int i = 0; i <= n; i++) {
            int l;
            cin >> l;
            total += l;
            v.pb(vector<int>(l, 0));
            int s = sz(v) - 1;
            for (int j = 0; j < l; j++) {
                int temp;
                cin >> temp;
                v[s][j] = temp;
                m[temp]++;
            }
            sort(all(v[s]));
        }
        for (int i = 0; i <= n; i++) {
            bool temp = false;
            int cur = -1;
            for (int j = 0; j < sz(v[i]); j++) {
                if (v[i][j] == cur) continue;
                else if (v[i][j] == (cur + 1)) {
                    cur++;
                    continue;
                } else {
                    temp = true;
                    MEX[i].ff = cur + 1;
                    cur++;
                    while (j < sz(v[i])) {
                        if (v[i][j] == cur) j++;
                        else if (v[i][j] == (cur + 1)) {cur++; j++;}
                        else break;
                    }
                    MEX[i].ss = cur + 1;
                    break;
                }
            }
            if (!temp) {MEX[i].ff = cur + 1; MEX[i].ss = cur + 2;}
        }   
        ll sum = 0;
        
        for (int i = 0; i <= n; i++) {
            sum += MEX[i].ff;
            ans += (long long) m[MEX[i].ff] * (MEX[i].ss - MEX[i].ff);
            for (int j = 0; j < sz(v[i]); j++) {
                if (v[i][j] > MEX[i].ff) break;
                bool temp = false;
                while (j + 1 < sz(v[i]) && v[i][j] == v[i][j + 1]) {
                    j++;
                    temp = true;
                }
                if (temp) continue;
                ans -= (long long) (MEX[i].ff - v[i][j]) * n;
            }
        }
        ans += (long long) sum * n * total;
        cout << ans << "\n";
    }

    return 0;
}