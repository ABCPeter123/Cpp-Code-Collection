#include <iostream>
#include <vector>
using namespace std;

bool check(int x, int y, int value) {
    return (x >= 1 && y - value >= 0);
}

void print(vector<int> set) {
    for (auto i : set) {
        cout << i << " ";
    }
    cout << endl;
}

void print_subset(vector<vector<bool>> dp, vector<int> set, int x, int y, vector<int> subset) {
    if (set[x] == y + 1) {
        subset.insert(subset.begin(), set[x]);
        print(subset);
        return;
    }
    if (y != dp[0].size() - 1 && x >= 1 && dp[x - 1][y]) {
        print_subset(dp, set, x - 1, y, subset);
    }
    if (x >= 1 && y >= set[x] && dp[x - 1][y - set[x]]) {
        subset.insert(subset.begin(), set[x]);
        print_subset(dp, set, x - 1, y - set[x], subset);
    }
    return;
}

void sum(vector<vector<bool>> dp, vector<int> set, int target) {
    for (int i = 0; i < dp[0].size(); i++) {
        if (set[0] == i + 1) dp[0][i] = true;
    }

    for (int i = 1; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            if (set[i] == j + 1) dp[i][j] = true;
            if (check(i, j, set[i])) {
                if (dp[i - 1][j - set[i]] || dp[i - 1][j]) dp[i][j] = true;
            }
            else {
                if (dp[i - 1][j]) dp[i][j] = true;
            }
        }
    }

    for (int i = 0; i < dp.size(); i++) {
        if (dp[i][dp[0].size() - 1]) {
            print_subset(dp, set, i, target - 1, {});
        }
    }
}

int main() {
    vector<vector<bool>> dp;
    vector<int> set = { 3, 34, 4, 12, 5, 2 };
    int target = 9;
    for (int i = 0; i < set.size(); i++) {
        dp.push_back({});
        for (int j = 0; j < target; j++) {
            dp[i].push_back(false);
        }
    }
    sum (dp, set, target);
}