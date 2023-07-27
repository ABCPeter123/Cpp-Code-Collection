#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int dp[100][100];

int mult_memo(vector<int> array, int head, int tail) {
    if (tail == head) return 0;
    if (dp[head][tail] != -1) return dp[head][tail];
    dp[head][tail] = INT_MAX;
    for (int sep = head; sep < tail; sep++) {
        dp[head][tail] = min(dp[head][tail], mult_memo(array, head, sep) + mult_memo(array, sep + 1, tail) + array[head - 1] * array[sep] * array[tail]);
    }
    return dp[head][tail];
}

int mult_tabu(vector<int> array) {
    int dp[array.size()][array.size()];

    for (int i = 0; i < array.size(); i++) {
        dp[i][i] = 0;
    }

    for (int L = 2; L < array.size(); L++) {
        for (int i = 1; i < array.size() - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int sep = i; sep < j; sep++) {
                int count = dp[i][sep] + dp[sep + 1][j] + array[i - 1] * array[sep] * array[j];
                if (count < dp[i][j]) dp[i][j] = count;
            }
        }
    }

    return dp[1][array.size() - 1];
}

// int main() {
//     memset(dp, -1, sizeof dp);
//     vector<int> array = {1, 2, 3, 4, 3};
//     cout << mult_memo(array, 1, 4) << endl;

//     cout << mult_tabu(array) << endl;
// }