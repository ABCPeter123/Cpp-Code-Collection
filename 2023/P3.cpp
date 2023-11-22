#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int N,M,R,C;
    cin >> N >> M >> R >> C;
    char poster[N][M];
    memset(poster, 'a', M * N);
    if ((R == N || M == C) && !(R == N && M == C) && !(R == 0 || C == 0)) {
        if ((R == N && (M % 2 == 0) && (M + C) % 2 == 1) || (M == C && (N % 2 == 0) && (N + R) % 2 == 1)) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    if (C == M) {
        if (R % 2 == 0) {
            for (int i = (R / 2); i < (N - R / 2); i++) poster[i][M - 1] = 'b';
        }
        else {
            for (int i = 0; i < N; i++) poster[i][M - 1] = 'b';
            for (int i = ((N - R) / 2); i < ((N + R) / 2); i++) poster[i][M - 1] = 'a';
        }
    } else if (R == N) {
        if (C % 2 == 0) {
            for (int i = (C / 2); i < (M - C / 2); i++) poster[N - 1][i] = 'b';
        }
        else {
            for (int i = 0; i < M; i++) poster[N - 1][i] = 'b';
            for (int i = (M - C) / 2; i < (M + C) / 2; i++) poster[N - 1][i] = 'a';
        }
    } else {
        for (int i = R; i < N; i++) {
            poster[i][M - 1] = 'b';
        }
        for (int j = C; j < M; j++) {
            poster[N - 1][j] = 'b';
        }
        if (R == 0 || C == 0) {
            poster[N - 1][M - 1] = 'c';
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << poster[i][j];
        }
        cout << "\n";
    }
}