#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    bool row[m];
    bool col[n];
    memset(row, false, sizeof row);
    memset(col, false, sizeof col);
    for (int i = 0; i < k; i++) {
        char color;
        cin >> color;
        int num;
        cin >> num;
        if (color == 'R') row[num - 1] == true ? row[num - 1] = false : row[num - 1] = true;
        if (color == 'C') col[num - 1] == true ? col[num - 1] = false : col[num - 1] = true;
    }

    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (row[i] == col[j]) cout << "B";
    //         else cout << "G";
    //     }
    //     cout << "\n";
    // }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (row[i] != col[j]) cnt++;
        }
    }
    cout << cnt;
}