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

struct Node {
    ll val;
    int l, r;
    Node* left, *right;
};
 
Node* make_tree(vector<int> &v, int rl, int rr) {
    Node *head = new Node();
    if (rl == rr) {
        head -> val = v[rl - 1];
        head -> left = NULL;
        head -> right = NULL;
        head -> l = rl;
        head -> r = rr;
        return head;
    }
    head -> left = make_tree(v, rl, rr - (rr - rl + 1) / 2);
    head -> right = make_tree(v, rl + (rr - rl + 1) / 2, rr);
    head -> val = head -> left -> val ^ head -> right -> val;
    head -> l = rl;
    head -> r = rr;
    return head;
}
 
void print_tree(Node* head) {
    if (!head -> left) {cout << head -> val << "\n"; return;}
    print_tree(head -> left);
    cout << head -> val << "\n";
    print_tree(head -> right);
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        n = pow(2, n);
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        Node* head = make_tree(v, 1, n);
        while (q--) {
            int b, c;
            int ans = 0;
            cin >> b >> c;
            Node* trav = head;
            while (trav -> left) {
                if (trav -> left -> l <= b && b <= trav -> left -> r) {
                    ll var = trav -> left -> val ^ v[b - 1] ^ c;
                    if (var < trav -> right -> val) ans += trav -> right -> r - trav -> right -> l + 1;
                    trav = trav -> left;
                } else {
                    ll var = trav -> right -> val ^ v[b - 1] ^ c;
                    if (trav -> left -> val >= var) ans += trav -> left -> r - trav -> left -> l + 1;
                    trav = trav -> right;
                }
            }
            cout << ans << "\n";
        }
        delete head;
    }
} 

/**
if in same pair, win + 0, lose + 1, XOR value is the same (updated)
continue with the local pair, win + 0, lose + 2, etc..
 */