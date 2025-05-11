#include <bits/stdc++.h>
using namespace std;

int main() {
    long n,c;
    cin >> n >> c;
    long ans = n * (n - 1) * (n - 2) / 6;
    vector<long> count(c, 0);
    vector<long> tot(c, 0);
    for (long i = 0; i < n; i++) {
        long temp;
        cin >> temp;
        count[temp]++;
    }
    tot[0] = count[0];
    for (long i = 1; i < c; i++) {
        tot[i] = tot[i - 1] + count[i];
    }
    for (long i = 0; i < c; i++) {
        long opp = (i + c / 2) % c;
        long between;
        if (opp >= i) {
            between = tot[opp] - tot[i];
        } else {
            between = tot[c - 1] - tot[i] + tot[opp];
        }
        // cout << ans << endl;
        // cout << between << " " << i << " " << opp << endl;
        ans -= count[i] * between * (between - 1) / 2;
        ans -= count[i] * (count[i] - 1) * between / 2;
        ans -= count[i] * (count[i] - 1) * (count[i] - 2) / 6;
    }

    if (c % 2 == 0) {
        for (long i = 0; i < c / 2; i++) {
            long opp = (i + c / 2) % c;
            ans += count[i] * count[opp] * (count[opp] - 1) / 2;
            ans += count[i] * (count[i] - 1) * count[opp] / 2;
        }
    }
    cout << ans << endl;


}