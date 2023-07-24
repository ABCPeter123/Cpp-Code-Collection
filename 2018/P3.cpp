#include <vector>
#include <iostream>
#include <string>
using namespace std;

vector<vector<string>> map;

void camera(int x, int y) {
    for (int i = y + 1; i <= map.size() - 1; i++) {
        if (map[i][x].find("W") != -1) break;
        else if (map[i][x].find("U") != -1 || map[i][x].find("L") != -1 || map[i][x].find("R") != -1 || map[i][x].find("D") != -1) continue;
        map[i][x] += 'C';
    }
    for (int i = y - 1; i >= 0; i--) {
        if (map[i][x].find("W") != -1) break;
        else if (map[i][x].find("U") != -1 || map[i][x].find("L") != -1 || map[i][x].find("R") != -1 || map[i][x].find("D") != -1) continue;
        map[i][x] += 'C';
    }
    for (int i = x + 1; i <= map[0].size() - 1; i++) {
        if (map[y][i].find("W") != -1) break;
        else if (map[y][i].find("U") != -1 || map[y][i].find("L") != -1 || map[y][i].find("R") != -1 || map[y][i].find("D") != -1) continue;
        map[y][i] += 'C';
    }
    for (int i = x - 1; i >= 0; i--) {
        if (map[y][i].find("W") != -1) break;
        else if (map[y][i].find("U") != -1 || map[y][i].find("L") != -1 || map[y][i].find("R") != -1 || map[y][i].find("D") != -1) continue;
        map[y][i] += 'C';
    }
}

bool stuck(int x, int y) {
    if (x < 0 || x >= map[0].size() || y < 0 || y >= map.size()) return true;
    if (map[y][x].find('S') != -1) return true;
    if (map[y][x].find("W") != -1) return true;
    if (map[y][x].find("C") != -1) return true;
    if (map[y][x].find("R") != -1 && (map[y][x + 1].find("W") != -1 || map[y][x + 1].find("C") != -1)) return true;
    if (map[y][x].find("L") != -1 && (map[y][x - 1].find("W") != -1 || map[y][x - 1].find("C") != -1)) return true;
    if (map[y][x].find("D") != -1 && (map[y + 1][x].find("W") != -1 || map[y + 1][x].find("C") != -1)) return true;
    if (map[y][x].find("U") != -1 && (map[y - 1][x].find("W") != -1 || map[y - 1][x].find("C") != -1)) return true;
    return false;
}

bool belt(int &x, int &y) {
    bool check = false;
    while (map[y][x].find("R") != -1 || map[y][x].find("L") != -1 || map[y][x].find("D") != -1 || map[y][x].find("U") != -1) {
        map[y][x] += 'S';
        if (map[y][x].find("R") != -1) x++;
        if (map[y][x].find("L") != -1) x--;
        if (map[y][x].find("D") != -1) y++;
        if (map[y][x].find("U") != -1) y--;
        check = true;
    }
    return check;
}

void dynamic_recursion(vector<vector<int>>& array, int x, int y, int n) {
    if (stuck(x, y)) return;
    if (map[y][x].find(".") != -1) {array[y][x] = n;}
    if (belt(x, y)) {
        dynamic_recursion(array, x, y, n);
        return;
    }
    map[y][x] += 'S';
    if (!stuck(x + 1, y)) {dynamic_recursion(array, x + 1, y, n + 1);}
    if (!stuck(x - 1, y)) {dynamic_recursion(array, x - 1, y, n + 1);}
    if (!stuck(x, y + 1)) {dynamic_recursion(array, x, y + 1, n + 1);}
    if (!stuck(x, y - 1)) {dynamic_recursion(array, x, y - 1, n + 1);}
}

int main() {
    int n,m,x,y;
    cin >> n >> m;
    vector<vector<int>> cameras;
    vector<vector<int>> exit_points;
    for (int i = 0; i < n; i++) {
        map.push_back({});
        exit_points.push_back({});
        for (int j = 0; j < m; j++) {
            char a;
            cin >> a;
            if (a == 'C') cameras.push_back({j, i});
            if (a == 'S') {x = j; y = i; map[i].push_back(" "); exit_points[i].push_back(0); continue;}
            if (a == '.') {exit_points[i].push_back(-1);}
            else exit_points[i].push_back(0);
            string temp = "";
            temp += a;
            map[i].push_back(temp);
        }
    }
    for (auto i : cameras) {
        camera(i[0], i[1]);
    }
    dynamic_recursion(exit_points, x, y, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (exit_points[i][j] != 0) cout << exit_points[i][j] << "\n";
        }
    }
}

