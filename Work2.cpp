#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n, temp;
    vi x;
    int a = INT_MIN, b = INT_MIN;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        bool lol = false;
        a = INT_MIN, b = INT_MIN;
        x = {};
        for (int j = 0; j < n; j++) {
            cin >> temp;
            if (temp % 2 == 0) {
                if (a == INT_MIN) a = temp;
                else if (b == INT_MIN) {
                    cout << a << " " << temp << "\n";
                    lol = true;
                    break;
                }
            } else {
                x.push_back(temp);
            }
        }
        if (lol) continue;
        lol = false;
        for (int j = 0; j < x.size() - 1; j++) {
            for (int k = j + 1; k < x.size(); k++) {
                if (2 * x[j] > x[k]) {
                    cout << x[j] << " " << x[k] << "\n";
                    lol = true;
                    break;
                } else if ((x[k] % x[j]) % 2 == 0) {
                    cout << x[j] << " " << x[k] << "\n";
                    lol = true;
                    break;
                }
            }
            if (lol) break;
        }
        if (!lol) cout << "-1\n";
        
    }
    
}
