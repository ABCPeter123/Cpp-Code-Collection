// #include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>> solution, int row, int column) {
    for (int i = 0; i < solution.size(); i++) {
        if (solution[i][column] == 'Q' || solution[row][i] == 'Q') return false;
    }
    int i, j;
    for (i = row, j = column; i >= 0 && j >= 0; i--, j--) {
        if (solution[i][j] == 'Q') return false;
    }

    for (i = row, j = column; i >= 0 && j < solution.size(); i--, j++) {
        if (solution[i][j] == 'Q') return false;
    }
    return true;
}

bool nqueen(int n, vector<vector<char>>& solution, int row) {
    if (row >= n) return true;

    for (int column = 0; column < n; column++) {
        if (isSafe(solution, row, column)) {
            solution[row][column] = 'Q';
            
            if (nqueen(n, solution, row + 1)) return true;
            else solution[row][column] = '.';
        }
    }
    return false;
}

// int main() {
//     int n = 4;
//     vector<vector<char>> solution;
//     for (int i = 0; i < n; i++) {
//         solution.push_back({});
//         for (int j = 0; j < n; j++) solution[i].push_back('.');
//     }
//     if (nqueen(n, solution, 0)) {
//         for (auto i : solution) {
//             for (auto j : i) cout << j << " ";
//             cout << "\n";
//         }
//     } else cout << "solution does not exist" << endl;
// }