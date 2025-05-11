#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,r,c;
    cin >> n >> m >> r >> c;
    if (r == 0 && c == 0) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) cout << "a";
            cout << "b\n";
        }
        for (int j = 0; j < m - 1; j++) cout << "b";
        cout << "c";
        return 0;
    }
    if (r == n && c == m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cout << "a";
            cout << "\n";
        }
        return 0;
    }
    if (m == c) {
        if (r % 2 == 1 && n % 2 == 0) {cout << "IMPOSSIBLE"; return 0;}
        if (r % 2 == 1) {
            for (int i = 0; i < (r - 1) / 2; i++) {
                for (int j = 0; j < m; j++) cout << "a";
                cout << "\n";
            }
            for (int i = (r - 1) / 2; i < (n - 1) / 2; i++) {
                cout << "a";
                for (int j = 1; j < m; j++) cout << "b";
                cout << "\n";
            }
            for (int j = 0; j < m; j++) cout << "a";
            cout << "\n";
            for (int i = (r - 1) / 2; i < (n - 1) / 2; i++) {
                cout << "a";
                for (int j = 1; j < m; j++) cout << "b";
                cout << "\n";
            }
            for (int i = 0; i < (r - 1) / 2; i++) {
                for (int j = 0; j < m; j++) cout << "a";
                cout << "\n";
            }
            return 0;
        }
        for (int i = 0; i < r / 2; i++) {
            for (int j = 0; j < m; j++) cout << "a";
            cout << "\n";
        }
        for (int i = r / 2; i < n - r / 2; i++) {
            cout << "a";
            for (int j = 1; j < m; j++) cout << "b";
            cout << "\n";
        }
        for (int i = 0; i < r / 2; i++) {
            for (int j = 0; j < m; j++) cout << "a";
            cout << "\n";
        }
        return 0;
    }
    if (n == r) {
        if (c % 2 == 1 && m % 2 == 0) {cout << "IMPOSSIBLE"; return 0;}
        if (c % 2 == 0) {
            for (int j = 0; j < m; j++) cout << "a";
            cout << "\n";
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < c / 2; j++) cout << "a";
                for (int j = c / 2; j < m - c / 2; j++) cout << "b";
                for (int j = 0; j < c / 2; j++) cout << "a";
                cout << "\n";
            }
            return 0;
        }
        for (int j = 0; j < m; j++) cout << "a";
        cout << "\n";
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < (c - 1) / 2; j++) cout << "a";
            for (int j = (c - 1) / 2; j < (m - 1) / 2; j++) cout << "b";
            cout << "a";
            for (int j = (c - 1) / 2; j < (m - 1) / 2; j++) cout << "b";
            for (int j = 0; j < (c - 1) / 2; j++) cout << "a";
            cout << "\n";
        }
        return 0;
    }
    if (r == 0) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < m; j++) cout << "a";
            cout << "\n";
        }
        for (int i = r; i < n - 1; i++) {
            for (int j = 0; j < c; j++) cout << "a";
            for (int j = c; j < m; j++) cout << "b";
            cout << "\n";
        }
        for (int j = 0; j < c; j++) cout << "a";
        for (int j = c; j < m; j++) cout << "c";
        return 0;
    }
    if (c == 0) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < m; j++) cout << "a";
            cout << "\n";
        }
        for (int i = r; i < n; i++) {
            for (int j = 0; j < c; j++) cout << "a";
            for (int j = c; j < m - 1; j++) cout << "b";
            cout << "c";
            cout << "\n";
        }
        return 0;
    }
    if (r < n && c < m) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < m; j++) cout << "a";
            cout << "\n";
        }
        for (int i = r; i < n; i++) {
            for (int j = 0; j < c; j++) cout << "a";
            for (int j = c; j < m; j++) cout << "b";
            cout << "\n";
        }
    }
}