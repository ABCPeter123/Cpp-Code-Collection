// #include <iostream>
#include <vector>
using namespace std;

bool riam(vector<vector<int>> board, vector<vector<int>>& solution, int x, int y) {
    if (x >= board.size() || y >= board.size()) return false;
    if (board[x][y] == 0) return false;
    else solution[x][y] = 1;
    if (x == board.size() - 1 && y == board.size() - 1) return true;
    if (riam(board, solution, x + 1, y)) return true;
    if (riam(board, solution, x, y + 1)) return true;
    solution[x][y] = 0;
    return false;
}

// int main() {
//     vector<vector<int>> solution;
//     vector<vector<int>> board = 
//     {
//     {1, 1, 1, 0},
//     {1, 0, 1, 1},
//     {1, 1, 0, 1},
//     {1, 0, 1, 1}
//     };
//     for (int i = 0; i < board.size(); i++) {
//         solution.push_back({});
//         for (int j = 0; j < board.size(); j++) solution[i].push_back(0);
//     }

//     if (riam(board, solution, 0, 0)) {
//         for (auto i : solution) {
//             for (auto j : i) cout << j << " ";
//             cout << "\n";
//         }
//     }
//     else cout << "solution does not exist" << endl;
// }