#include <bits/stdc++.h>
using namespace std;

int main() {
    long n;
    cin >> n;   
    vector<double> h;
    vector<double> w;
    for (int i = 0; i <= n; i++) {
        h.push_back(0);
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        w.push_back(0);
        cin >> w[i];
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (h[i] + h[i + 1]) * w[i] / 2.0;
    }
    cout << fixed << setprecision(5) << ans << endl;
}