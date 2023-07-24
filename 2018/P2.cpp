#include <iostream>
#include <vector>
#include <string>
using namespace std;

void check(vector<vector<int>> array, string &save) {
    for (int i = 0; i < array[0].size() - 1; i++) {
        if (array[0][i] > array[0][i + 1]) {
            save = "x";
            break;
        }
    }
    for (int i = 0; i < array.size() - 1; i++) {
        if (array[i][0] > array[i + 1][0]) {
            if (save == "x") {
                save = "xy";
            }
            else save = "y";
            break;
        }
    }
}

void rotate_counter_clockwise(vector<vector<int>> &array) {
    vector<int> temp;
    for (int x = array.size() - 1; x >= 0; x--) {
        for (int y = 0; y < array.size(); y++) {
            temp.push_back(array[y][x]);
        }
    }
    int n = 0;
    for (int y = 0; y < array.size(); y++) {
        for (int x = 0; x < array.size(); x++) {
            array[y][x] = temp[n];
            n++;
        }
    }
}

void rotate_clockwise(vector<vector<int>> &array) {
    vector<int> temp;
    for (int x = 0; x < array.size(); x++) {
        for (int y = array.size() - 1; y >= 0; y--) {
            temp.push_back(array[y][x]);
        }
    }
    int n = 0;
    for (int y = 0; y < array.size(); y++) {
        for (int x = 0; x < array.size(); x++) {
            array[y][x] = temp[n];
            n++;
        }
    }
}

void flip(vector<vector<int>> &array) {
    vector<int> temp;
    for (int y = array.size() - 1; y >= 0; y--) {
        for (int x = array.size() - 1; x >= 0; x--) {
            temp.push_back(array[y][x]);
        }
    }
    int n = 0;
    for (int y = 0; y < array.size(); y++) {
        for (int x = 0; x < array.size(); x++) {
            array[y][x] = temp[n];
            n++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> plants;
    for (int i = 0; i < n; i++) {
        plants.push_back({});
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            plants[i].push_back(a);
        }
    }
    string save = "";
    check(plants, save);
    if (save == "x") {
        rotate_counter_clockwise(plants);
    } else if (save == "y") {
        rotate_clockwise(plants);
    } else if (save == "xy") {
        flip(plants);
    }
    for (auto i : plants) {
        for (auto j : i) cout << j << " ";
        cout << "\n";
    }
}