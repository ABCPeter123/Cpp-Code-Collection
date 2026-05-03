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

struct SegTree {
    int n;
    vector<ll> tree;

    SegTree() {}
    SegTree(int n_) { init(n_); }

    void init(int n_) {
        n = 1;
        while (n < n_) n <<= 1;
        tree.assign(2 * n, 0);
    }

    void build(const vector<ll>& a) {
        for (int i = 0; i < sz(a); i++) tree[n + i] = a[i];
        for (int i = n - 1; i >= 1; i--) tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    void setval(int idx, ll val) {
        idx += n;
        tree[idx] = val;
        for (idx >>= 1; idx >= 1; idx >>= 1) {
            tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
            if (idx == 1) break;
        }
    }

    ll query(int l, int r) {
        // inclusive [l, r]
        ll res = 0;
        l += n;
        r += n;
        while (l <= r) {
            if (l & 1) res += tree[l++];
            if (!(r & 1)) res += tree[r--];
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        multiset<int> m;
        int cur = 0;

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