#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> solution, int x, int y) {
    return (x >= 0 && x < solution.size() && y >= 0 && y < solution.size() && solution[x][y] == -1);
}

bool backtrack(vector<vector<int>>& solution, vector<int> move_x, vector<int> move_y, int x, int y, int move) {
    if (move == solution.size() * solution.size()) return true;
    for (int k = 0; k < 8; k++) {
        int next_x = x + move_x[k];
        int next_y = y + move_y[k];
        if (isSafe(solution, next_x, next_y)) {
            solution[next_x][next_y] = move;
            if (backtrack(solution, move_x, move_y, next_x, next_y, move + 1)) {
                return true;
            } else solution[next_x][next_y] = -1;
        }
    }
    return false;
}

void knight(int n) {
    vector<vector<int>> solution;
    for (int i = 0; i < n; i++) {
        solution.push_back({});
        for (int j = 0; j < n; j++) solution[i].push_back(-1);
    }
    vector<int> move_x = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> move_y = {1, 2, 2, 1, -1, -2, -2, -1};

    solution[0][0] = 0;
    if (backtrack(solution, move_x, move_y, 0, 0, 1)) {
        for (auto i : solution) {
            for (auto j : i) cout << j << " ";
            cout << "\n";
        }
    } else {
        cout << "Solution does not exist!" << endl;
    }
    
}

int main() {
    knight(8);
}