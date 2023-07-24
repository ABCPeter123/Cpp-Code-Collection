#include <iostream>
#include <vector>
using namespace std;

int main() {
    int score[4];
    vector<vector<int>> game = {{0,0,0}, {0,0}, {0}};
    int target;
    cin >> target;
    target--;
    int n, n1, n2, n3, n4;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> n1 >> n2 >> n3 >> n4;
        game[--n1][n2 - n1 - 1]++;
        if (n3 < n4) {
            score[--n1] += 3;
        } else if (n3 > n4) {
            score[--n2] += 3;
        } else {
            score[--n1] += 1;
            score[--n2] += 1;
        }
    }
    for (int i = 1; i <= 3 * (6 - n); i++) {
        if (game[0][0] == 0) 
    }
}