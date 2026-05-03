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
        int n, m, h;
        cin >> n >> m >> h;
        vector<int> v(n, 0);
        vector<int> vc(n, 0);
        vector<int> inst(n, -1);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            vc[i] = v[i];
        }
        int reset = -1;
        for (int i = 0; i < m; i++) {
            int b, c;
            cin >> b >> c;
            b--;

            if (inst[b] < reset) vc[b] = v[b];
            vc[b] += c;
            if (vc[b] > h) {
                reset = i;
                vc[b] = v[b];
            }
            inst[b] = i;
        }
        for (int i = 0; i < n; i++) {
            if (inst[i] < reset) vc[i] = v[i];
        }
        for (int i : vc) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}