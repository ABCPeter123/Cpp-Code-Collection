#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N,M,R,C;
    cin >> N >> M >> R >> C ;
    vector<vector<char>> poster[N][M];
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