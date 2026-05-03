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
        vector<int> v6;
        vector<int> v2;
        vector<int> v3;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            if (temp % 6 == 0) v6.pb(temp);
            else if (temp % 3 == 0) v3.pb(temp);
            else if (temp % 2 == 0) v2.pb(temp);
            else v.pb(temp);
        }
        for (int i : v6) cout << i << " ";
        for (int i : v3) cout << i << " ";
        for (int i : v) cout << i << " ";
        for (int i : v2) cout << i << " ";
        cout << "\n";
    }
 
    return 0;
}