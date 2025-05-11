#include <iostream>
#include <vector>
using namespace std;
#define INT_MAX 9223372036854775807
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    cout << 0 << " ";
    if (n == 1) return 0;
    if (n == 2) {cout << abs(h[1] - h[0]); return 0;}

    vector<vector<ll>> dp(n - 2, vector<ll>());

    for (int i = 0; i < n - 1; i++) {
        ll minimum = INT_MAX;
        for (int j = 0; j < n - 1 - i; j++) {
            ll temp = abs(h[j] - h[j + i + 1]);
            if (i >= 2) temp += dp[i - 2][j];
            minimum = min(temp, minimum);
            if (j > 0 && j < n - 2 - i) dp[i].push_back(temp);
        }
        cout << minimum << " ";
    }
    // cout << "\n";
    // for (auto i : dp) {
    //     for (auto j : i) cout << j << " ";
    //     cout << "\n";
    // }
}