// #include <iostream>
#include <vector>
using namespace std;

int LIS(vector<int> array, int index, int* max) {
    if (index == 0) return 1;
    int result, local_max = 1;
    for (int i = 0; i < index; i++) {
        if (array[i] < array[index]) {
            result = LIS(array, i, max);
            if (result + 1 > local_max) local_max = result + 1;
        }
    }

    if (local_max > *max) *max = local_max;

    return local_max;
}

int LIS(vector<int> array) {
    int max = 1;

    LIS(array, array.size() - 1, &max);

    return max;
}

// int main() {
//     vector<int> array = {10, 22, 9, 33, 21, 50, 41, 60};
//     cout << LIS(array) << endl;
// }