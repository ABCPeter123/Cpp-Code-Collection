#include <bits/stdc++.h>
using namespace std;

int main() {
    long n,m,k; 
    cin >> n >> m >> k; 
    vector<long> ans; 
    for(long i = 0; i < n; i++) {
        long rem = n - i - 1; 
        long cur = min(k - rem, m);
        if (cur <= 0) break;  
        long val; 
        if(cur > i) {
            val = min(m, i + 1);
            cur = val; 
        }
        else val = ans[i - cur]; 
        ans.push_back(val);
        k = k - cur; 
    }

    if(k == 0 && (long) ans.size() == n) {
        for(auto x: ans) cout << x << ' '; 
        cout << endl; 
    }
    else cout << -1 << endl;
}