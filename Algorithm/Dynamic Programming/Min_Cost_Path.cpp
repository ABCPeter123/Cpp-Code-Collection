#include <iostream>
#include <vector>
using namespace std;

void print_path(vector<vector<int>> cost, vector<vector<int>> grid) {
    int x = cost.size() - 1;
    int y = cost[0].size() - 1;
    vector<vector<int>> path;
    while (x != 0 && y != 0) {
        path.insert(path.begin(), {x, y});
        if (cost[x][y] - grid[x][y] == cost[x - 1][y]) x -= 1;
        else if (cost[x][y] - grid[x][y] == cost[x][y - 1]) y -= 1;
        else if (cost[x][y] - grid[x][y] == cost[x - 1][y - 1]) {x -= 1; y -= 1;}
    }
    while (y != 0) {
        path.insert(path.begin(), {0, y});
        y--;
    }
    while (x != 0) {
        path.insert(path.begin(), {x, 0});
        x--;
    }
    path.insert(path.begin(), {0, 0});
    for (auto i : path) {
        cout << "(" << i[0] << ", " << i[1] << ")" << endl; 
    }
}

void min_path(vector<vector<int>> grid) {
    vector<vector<int>> cost;
    cost.push_back({grid[0][0]});
    for (int i = 1; i < grid[0].size(); i++) {
        cost[0].push_back(grid[0][i] + cost[0][i - 1]);
    }
    for (int i = 1; i < grid.size(); i++) {
        cost.push_back({grid[i][0] + cost[i - 1][0]});
    }
    for (int i = 1; i < grid.size(); i++) {
        for (int j = 1; j < grid[i].size(); j++) {
            cost[i].push_back(min(cost[i - 1][j - 1], min(cost[i - 1][j], cost[i][j - 1])) + grid[i][j]);
        }
    }
    for (auto i : cost) {
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    cout << "The minimum cost is " << cost[grid.size() - 1][grid[0].size() - 1] << endl;
    print_path(cost, grid);
}

// int main() {
//     vector<vector<int>> grid = 
//     {
//     {2, 1, 4, 5, 2, 9, 3},
//     {4, 8, 2, 2, 4, 0, 1},
//     {1, 5, 3, 3, 9, 1, 4},
//     {4, 1, 2, 0, 0, 0, 4}
//     };
//     min_path(grid);
// }