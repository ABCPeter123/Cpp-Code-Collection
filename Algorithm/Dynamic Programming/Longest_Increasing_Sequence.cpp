#include <iostream>
#include <vector>
using namespace std;

void LIS(vector<int> array) {
    vector<vector<int>> lis;
    vector<int> length;
    length.push_back(1);
    lis.push_back({array[0]});
    int max = 0;
    int max_index = -1;
    for (int i = 1; i < array.size(); i++) {
        length.push_back(1);
        int index = -1;
        for (int j = 0; j < i; j++) {
            if (array[i] > array[j] && length[i] < length[j] + 1) {
                length[i] = length[j] + 1;
                index = j;
            }
        }
        if (length[i] > max) {
            max = length[i];
            max_index = i;
        }
        if (index != -1) {
            lis.push_back(lis[index]);
            lis[i].push_back(array[i]);
        }
        else {
            lis.push_back({});
            lis[i].push_back(array[i]);
        }
    }

    cout << "The maximum length is " << max << endl;
    cout << "The sequence is: " << endl;
    for (auto i : lis[max_index]) cout << i << " ";
}

int main() {
    vector<int> array = {10, 22, 9, 33, 21, 50, 41, 60};
    LIS(array);
}