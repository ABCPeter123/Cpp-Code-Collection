#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, temp;
        cin >> n;
        vector<pair<int, int>> v = {make_pair(0, n - 2)};
        n--;
        cin >> temp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        for (int i = 0; i < n; i++) {
            int temp2;
            cin >> temp2;
            pq.push(make_pair(abs(temp2 - temp), i));
            temp = temp2;
        }
        long long ans = (long long) n * (n + 1) / 2;
        for (int i = 1; i <= n; i++) {
            while (!pq.empty() && pq.top().first < i) {
                int ind = pq.top().second;
                pq.pop();
                int l = 0, r = v.size() - 1, target;
                while (l <= r) {
                    if (l == r) {target = l; break;}
                    int mid = (l + r) / 2;
                    if (v[mid].first <= ind && ind <= v[mid].second) {
                        target = mid; break;
                    } else if (ind < v[mid].first) {
                        r = mid;
                    } else l = mid + 1;
                }
                l = v[target].first;
                r = v[target].second;
                int m = r - l + 1;
                int k = ind - l;
                ans += (long long) k * k + k - (long long) (k + 1) * m;
                v.erase(v.begin() + target);
                if (ind + 1 <= r) v.insert(v.begin() + target, make_pair(ind + 1, r));
                if (ind - 1 >= l) v.insert(v.begin() + target, make_pair(l, ind - 1));
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
    
    return 0;
}