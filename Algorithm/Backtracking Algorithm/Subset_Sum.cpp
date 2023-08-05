#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> array) {
    for (auto i : array) cout << i << " ";
    cout << endl;
}

void sum(vector<int> set, vector<int>& subset, int target, int index) {
    if (target == 0) {
        print(subset);
        return;
    }
    if (index == set.size()) return;
    sum(set, subset, target, index + 1);
    if (set[index] <= target) {
        subset.push_back(set[index]);
        sum(set, subset, target - set[index], index + 1);
        subset.pop_back();
    }
}

int main() {
    vector<int> subset = {};
    vector<int> set = {1, 2, 1};
    int target = 3;
    sum(set, subset, target, 0);
}

/**
 * 1 2 1 --> 3
 * 1 2 
 * 1   1
 *   2 
 *   2 1
 * 2 ^ n
*/