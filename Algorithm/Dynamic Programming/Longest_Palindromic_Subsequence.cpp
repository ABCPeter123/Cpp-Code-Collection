// #include <iostream>
#include <string.h>
#include <string>
using namespace std;

int dp[100][100];

int LPS(string sequence, int head, int tail) {
    if (head == -1 || tail == -1) return 0;
    if (head == tail) {
        dp[head][tail] = 1;
        return 1;
    }
    if (head == tail - 1 && sequence[head] == sequence[tail]) {
        dp[head][tail] = 2;
        return 2;
    }
    if (sequence[head] != sequence[tail]) {
        dp[head][tail] = max(LPS(sequence, head + 1, tail), LPS(sequence, head, tail - 1));
    }
    else {
        dp[head][tail] = 2 + LPS(sequence, head + 1, tail - 1);
    }
    return dp[head][tail];
}

// int main() {
//     memset(dp, -1, sizeof dp);
//     cout << LPS("BBABCBCAB", 0, 8);
// }