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
        vector<int> v(n, 0);
        vector<int> freq(n + 2, 0); // how many for each height
        vector<ll> sind(n + 2, 0); // sum of indices of some height
        vector<int> sfreq(n + 2, 0); // suffix of freq
        vector<ll> ssind(n + 2, 0); // suffix of sind
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            v[i] = temp;
            freq[temp]++;
            sind[temp] += i + 1;
        }
 
        for (int i = n; i >= 1; i--) {
            sfreq[i] = sfreq[i + 1] + freq[i];
            ssind[i] = ssind[i + 1] + sind[i];
        }
        ll old = 0;
        for (int i = 1; i <= n; i++) {
            ll k = sfreq[i];
            ll sum = ssind[i];
 
            old += k * (n - k) + k * (k + 1) / 2 - sum;
        }
 
        ll ma = 0;
        for (int i = 1; i <= n; i++) {
            ll k = sfreq[v[i - 1]];
            ma = max(ma, i - n + k - 1);
        }
        cout << old + ma << "\n";
 
    }
 
    return 0;
}