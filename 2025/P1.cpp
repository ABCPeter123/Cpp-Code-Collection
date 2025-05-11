#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cerr << #x << " = " << x << "\n";

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = INT_MAX;
    ans = min(ans, max(a, c) + b + d);
    ans = min(ans, max(b, d) + a + c);
    cout << ans * 2;
}
