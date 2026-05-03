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
const ll MOD = 1e9 + 7;

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
        int p, q;
        cin >> p >> q;
        int m = 2 * p + 4 * q + 1;
        bool te = true;
        for (int i = 3; i <= sqrt(m); i += 2) {
            if (m % i) continue;
            int r = m / i;
            int i1 = (i - 1) / 2;
            int r1 = (r - 1) / 2;
            if (i1 > 0 && r1 > 0) {
                if (q <= min((i1 + 1) * r1, (r1 + 1) * i1)) {
                    te = false;
                    cout << i1 << " " << r1 << "\n";
                    break;
                }
            }
        }
        if (te) cout << "-1\n";
    }
}