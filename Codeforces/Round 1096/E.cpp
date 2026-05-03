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
        vector<vector<int>> dp(n, vector<int>(2, 0));
        for (int i = 0; i < n; i++) {
            cin >> dp[i][1];
        }
        ll ans = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (dp[i + 1][0] < 0) dp[i][0] = dp[i][1] - dp[i + 1][1];
            else dp[i][0] = dp[i][1] - dp[i + 1][1] + dp[i + 1][0];
            if (dp[i][0] < 0) ans += 0;
            else ans += dp[i][0];
        }
        ll ma = 0;
        ll cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (dp[i][0] <= 0) {
                i--;
                while (i >= 0 && dp[i][0] + 1 > 0) {cnt++; i--;}
                ma = max(ma, cnt);
                cnt = 0;
                i++;
            } else {
                continue;
            }
        }
        cout << ans + ma << "\n";
    }
 
    return 0;
}