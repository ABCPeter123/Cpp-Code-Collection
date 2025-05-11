#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int>> seen;
vector<vector<int>> room;

int rec(int r, int c) {
    
    if (r >= m || c >= n) return 0;
    if (r == m - 1 && c == n - 1) return 1;
    if (seen[r][c] != -1) return seen[r][c];
    int cur = room[r][c];
    
    seen[r][c] = 2;
    int ans = 0;
    for (int i = 1; i <= floor(sqrt(cur)); i++) {
        if (cur % i == 0) {
            int temp = rec(i - 1, cur / i - 1);
            if (temp == 1) {
                ans = 1;
                break;
            }
            if (i != cur / i) {
                temp = rec(cur / i - 1, i - 1);
                if (temp == 1) {
                    ans = 1;
                    break;
                }
            }
        }
    }
    seen[r][c] = ans;

    return ans;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        seen.push_back({});
        room.push_back({});
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            room[i].push_back(temp);
            seen[i].push_back(-1);
        }
    }

    if(rec(0, 0)) cout << "yes\n";
    else cout << "no\n";
}

/*
5
6
3 8 10 7 12 2
3 9 10 5 17 9
25 28 29 30 13 11
17 16 15 13 18 16
19 20 23 25 6 35

5
5
4 4 4 4 4
4 4 4 4 4
4 4 4 4 4
4 4 4 4 4
4 4 4 4 4
*/