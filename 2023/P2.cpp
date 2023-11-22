#include <iostream>
#include <vector>
using namespace std;

vector<int> asymmetric(vector<int> heights, vector<vector<int>>& dp) {
    int n = heights.size();
    vector<int> results(n);
    results[0] = 0;
    for (int i = 2; i <= n; i++) {
        int minimum = 2147483647;
        for (int j = 0; j <= n - i; j++) {
            // cout << i << " " << j << endl;
            int value;
            if (i == 2) {
                value = abs(heights[j] - heights[j + 1]);
                dp[i - 1].push_back(value);
            }
            else {
                value = dp[i - 3][j + 1] + abs(heights[j] - heights[j + i - 1]);
                dp[i - 1].push_back(value);
            }
            
            // cout << value << " " << minimum << "\n" << endl;
            minimum = min(minimum, value);
        }
        results[i - 1] = minimum;
    }
    return results;
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    // int n = 5000;
    // vector<int> heights;
    // for (int i = 0; i < n; i++) {
    //     heights.push_back(47501 + i);
    // }
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; i++) dp[0].push_back(0);
    vector<int> val = asymmetric(heights, dp);
    for (int i = 0; i < n - 1; i++) cout << val[i] << " ";
    cout << val[n - 1];
}