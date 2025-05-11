#include <bits/stdc++.h>
using namespace std;

vector<long> p,w,d;

long long dis(int pos, int n) {
    long long count = 0;
    for (int i = 0; i < n; i++) {
        if ((long long) abs(pos - p[i]) <= d[i]) continue;
        count += (long long) (abs(pos - p[i]) - d[i]) * w[i];
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        p.push_back(0);
        w.push_back(0);
        d.push_back(0);
        cin >> p[i] >> w[i] >> d[i];
    }

    long long ans = LONG_MAX;
    int low = 0, high = 1e9;
    while (low <= high) {
        int mid = (low + high) / 2;
        ans = min(min(ans, dis(mid, n)), min(dis(mid - 1, n), dis(mid + 1, n)));
        if (dis(mid - 1, n) < dis(mid, n)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
}