#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int tiles[2][n];
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            cin >> tiles[j][i];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (tiles[0][i] == 1) {
            cnt += 3;
            if (i < n - 1 && tiles[0][i + 1] == 1) cnt -= 2;
            if (i % 2 == 0 && tiles[1][i] == 1) cnt--;
        }
    }
    for (int i = 0; i < n; i++) {
        if (tiles[1][i] == 1) {
            cnt += 3;
            if (i < n - 1 && tiles[1][i + 1] == 1) cnt -= 2;
            if (i % 2 == 0 && tiles[0][i] == 1) cnt--;
        }
    }
    cout << cnt;
}