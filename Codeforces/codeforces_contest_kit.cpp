/*
Codeforces Contest Kit, C++17
Use this as your personal prewritten template and notes.
Before using it in a rated contest, read the current rules for that contest.

Safe use:
1. Keep this file prepared before the contest starts.
2. Understand every template you copy.
3. Do not ask AI, friends, Discord, WeChat, or anyone for problem-specific help during the contest.
4. Do not copy someone else's contest solution.
5. During contest, use this as reference and type/adapt what you need.
*/

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

/*
============================================================
FAST DEBUG
============================================================
Uncomment LOCAL in your local compiler command if wanted:
g++ -std=c++17 -DLOCAL main.cpp
*/
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << (x) << '\n'
#else
#define dbg(x)
#endif

/*
============================================================
COMMON CHECKLIST
============================================================
Before submit:
1. Did I handle n = 1, empty, all equal, sorted, reversed?
2. Did I use long long for sums/products?
3. Did I clear data structures between test cases?
4. Did I check 0-based vs 1-based indexing?
5. Did I test impossible cases?
6. Did I test maximum constraints mentally?
7. Did I avoid recursion depth > 2e5?

Constraint to complexity hints:
n <= 20        bitmask, brute force, backtracking
n <= 100       O(n^3) maybe ok
n <= 500       O(n^3) maybe ok depending t
n <= 2000      O(n^2)
n <= 2e5      O(n log n) or O(n)
n <= 1e6      O(n) or O(n log n) with care
*/

/*
============================================================
MODULAR ARITHMETIC
============================================================
*/
ll modpow(ll a, ll b, ll mod = MOD) {
    ll res = 1 % mod;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll x, ll mod = MOD) {
    return modpow(x, mod - 2, mod);
}

/*
============================================================
COMBINATORICS nCr MOD PRIME
============================================================
Call init_comb(max_n) before using nCr.
*/
vector<ll> fact, invfact;

void init_comb(int N, ll mod = MOD) {
    fact.assign(N + 1, 1);
    invfact.assign(N + 1, 1);
    for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % mod;
    invfact[N] = modinv(fact[N], mod);
    for (int i = N - 1; i >= 0; i--) invfact[i] = invfact[i + 1] * (i + 1) % mod;
}

ll nCr(int n, int r, ll mod = MOD) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}

/*
============================================================
GCD, LCM
============================================================
*/
ll lcm_ll(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    return a / gcd(a, b) * b;
}

/*
============================================================
BINARY SEARCH PATTERNS
============================================================
*/
// First true in [lo, hi]
template <class F>
ll first_true(ll lo, ll hi, F ok) {
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (ok(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

// Last true in [lo, hi]
template <class F>
ll last_true(ll lo, ll hi, F ok) {
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (ok(mid)) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

/*
============================================================
PREFIX SUM
============================================================
Usage:
vector<ll> pref(n + 1);
for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];
Sum [l, r) = pref[r] - pref[l]
*/

/*
============================================================
2D PREFIX SUM
============================================================
For matrix a[n][m], 0-indexed.
Build p[n+1][m+1].
Rectangle sum rows [r1, r2), cols [c1, c2):
p[r2][c2] - p[r1][c2] - p[r2][c1] + p[r1][c1]
*/
vector<vector<ll>> build_2d_prefix(const vector<vector<int>>& a) {
    int n = sz(a), m = sz(a[0]);
    vector<vector<ll>> p(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            p[i][j] = a[i - 1][j - 1] + p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
        }
    }
    return p;
}

ll rect_sum(const vector<vector<ll>>& p, int r1, int c1, int r2, int c2) {
    return p[r2][c2] - p[r1][c2] - p[r2][c1] + p[r1][c1];
}

/*
============================================================
DSU, UNION FIND
============================================================
*/
struct DSU {
    vector<int> p, s;
    DSU() {}
    DSU(int n) { init(n); }

    void init(int n) {
        p.resize(n);
        s.assign(n, 1);
        iota(all(p), 0);
    }

    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (s[a] < s[b]) swap(a, b);
        p[b] = a;
        s[a] += s[b];
        return true;
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int size(int x) {
        return s[find(x)];
    }
};

/*
============================================================
GRAPH: BFS UNWEIGHTED SHORTEST PATH
============================================================
*/
vector<int> bfs_dist(const vector<vector<int>>& adj, int src) {
    int n = sz(adj);
    vector<int> dist(n, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

/*
============================================================
GRAPH: ITERATIVE DFS
============================================================
*/
vector<int> iterative_dfs_order(const vector<vector<int>>& adj, int src) {
    int n = sz(adj);
    vector<int> vis(n, 0), order;
    stack<int> st;
    st.push(src);
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        order.pb(u);
        for (int v : adj[u]) {
            if (!vis[v]) st.push(v);
        }
    }
    return order;
}

/*
============================================================
GRAPH: DIJKSTRA
============================================================
Adjacency list: vector<vector<pair<int,ll>>> adj
*/
vector<ll> dijkstra(const vector<vector<pair<int,ll>>>& adj, int src) {
    int n = sz(adj);
    vector<ll> dist(n, LINF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

/*
============================================================
GRAPH: TOPOLOGICAL SORT
============================================================
Returns empty if graph has a cycle.
*/
vector<int> topo_sort(const vector<vector<int>>& adj) {
    int n = sz(adj);
    vector<int> indeg(n, 0);
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) indeg[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.pb(u);
        for (int v : adj[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }
    if (sz(order) != n) return {};
    return order;
}

/*
============================================================
FENWICK TREE, BIT
============================================================
1-indexed internally. Use add(index, delta), sumPrefix(index), sumRange(l, r).
External indexes are 0-based.
*/
struct Fenwick {
    int n;
    vector<ll> bit;
    Fenwick() {}
    Fenwick(int n) { init(n); }

    void init(int n_) {
        n = n_;
        bit.assign(n + 1, 0);
    }

    void add(int idx, ll delta) {
        idx++;
        while (idx <= n) {
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }

    ll sumPrefix(int idx) {
        idx++;
        ll res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }

    ll sumRange(int l, int r) {
        if (l > r) return 0;
        return sumPrefix(r) - (l ? sumPrefix(l - 1) : 0);
    }
};

/*
============================================================
SEGMENT TREE, RANGE SUM, POINT UPDATE
============================================================
*/
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

/*
============================================================
GRID HELPERS
============================================================
*/
int dr4[4] = {1, -1, 0, 0};
int dc4[4] = {0, 0, 1, -1};
int dr8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dc8[8] = {1, 0, -1, 1, -1, 1, 0, -1};

bool inside(int r, int c, int n, int m) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

/*
============================================================
SIEVE
============================================================
*/
vector<int> sieve(int n) {
    vector<int> primes;
    vector<bool> is_prime(n + 1, true);
    if (n >= 0) is_prime[0] = false;
    if (n >= 1) is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.pb(i);
            if ((ll)i * i <= n) {
                for (ll j = (ll)i * i; j <= n; j += i) is_prime[j] = false;
            }
        }
    }
    return primes;
}

/*
============================================================
PRIME FACTORIZATION
============================================================
*/
vector<pair<ll,int>> factorize(ll x) {
    vector<pair<ll,int>> res;
    for (ll p = 2; p * p <= x; p++) {
        if (x % p == 0) {
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                cnt++;
            }
            res.pb({p, cnt});
        }
    }
    if (x > 1) res.pb({x, 1});
    return res;
}

/*
============================================================
LIS LENGTH, STRICTLY INCREASING
============================================================
*/
int lis_len(const vector<int>& a) {
    vector<int> d;
    for (int x : a) {
        auto it = lower_bound(all(d), x);
        if (it == d.end()) d.pb(x);
        else *it = x;
    }
    return sz(d);
}

/*
============================================================
MEX
============================================================
*/
int mex(vector<int> a) {
    int n = sz(a);
    vector<int> seen(n + 2, 0);
    for (int x : a) if (0 <= x && x <= n + 1) seen[x] = 1;
    for (int i = 0; i <= n + 1; i++) if (!seen[i]) return i;
    return n + 1;
}

/*
============================================================
COMMON SOLVE SHELL
============================================================
*/
void solve() {
    // Read input here.
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}

/*
============================================================
PATTERN NOTES
============================================================

1. Sorting + greedy
Use when order can reveal local choice.
Common examples: intervals, choose smallest ending, pair extremes, minimize max difference.

2. Prefix sum + hashmap
Use for subarray sum, parity count, modulo count.
If pref[j] - pref[i] = k, then need previous pref[i] = pref[j] - k.

3. Binary search on answer
Use when answer is numeric and feasibility is monotonic.
Examples: minimum maximum value, maximum minimum value, earliest time, capacity.

4. Two pointers
Use when expanding right and moving left preserves validity.
Usually works with positive values, counts, sorted arrays, or monotonic conditions.

5. DP
Define state first.
Then transition.
Then base case.
Then answer.
Common states:
dp[i] = best using first i elements
dp[i][j] = best using first i with condition j
dp[mask] = best subset state

6. Graph modeling
If problem says reachable, connected, dependency, transformation, shortest, components, think graph.
Grid can become graph using cell id = r * m + c.

7. Trees
For subtree problems, DFS returns information upward.
For path problems, think parent, depth, LCA, rerooting, or diameter.

8. Bit tricks
x & 1 checks odd.
x & -x gets lowest set bit.
__builtin_popcount(x), __builtin_popcountll(x).
Submasks:
for (int sub = mask; sub; sub = (sub - 1) & mask)

9. Common overflow traps
int * int overflows before assignment to long long.
Use 1LL * a * b.
mid = l + (r - l) / 2.

10. Contest strategy
Read A, B, C first.
Solve guaranteed problems first.
If stuck for 10 to 15 minutes with no new idea, switch.
After WA, find counterexample. Do not randomly patch.
Upsolve after contest and write down the missed pattern.
*/
