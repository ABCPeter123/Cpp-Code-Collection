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
        int l = 0, r = n;
        multiset<int> m;
        multiset<int> m1;
        while (n--) {
            int temp;
            cin >> temp;
            m.insert(temp);
        }
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            bool t = true;
            m1 = m;
            for (int k = mid - 1; k >= 0; k--) {
                auto exact = m1.find(k);
                if (exact != m1.end()) m1.erase(exact);
                else {
                    auto u = m1.upper_bound(2 * k);
                    if (u == m1.end()) {t = false; break;}
                    m1.erase(u);
                }
            }
            if (t) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << ans << "\n";
    }




    return 0;
}