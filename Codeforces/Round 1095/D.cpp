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
const ll MOD = 1e9 + 7;;

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int mae = INT_MIN, mie = INT_MAX;
        int mao = INT_MIN, mio = INT_MAX;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            v.pb(temp);
            if (temp % 2) {
                mao = max(mao, temp);
                mio = min(mio, temp);
            } else {
                mae = max(mae, temp);
                mie = min(mie, temp);
            }
        }
        int po = -1, pe = -1;
        bool te = true;
        for (int i = 0; i < n; i++) {
            if (v[i] % 2) {
                if (v[i] >= po) {
                    po = v[i];
                } else {
                    if (mie > v[i] && mae < po) {cout << "NO\n"; te = false; break;}
                }
            } else {
                if (v[i] >= pe) {
                    pe = v[i];
                } else {
                    if (mio > v[i] && mao < pe) {cout << "NO\n"; te = false; break;}
                }
            }
        }
        if (te) cout << "YES\n";
    }




    return 0;
}