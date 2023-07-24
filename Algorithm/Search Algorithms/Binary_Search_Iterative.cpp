#include <vector>
#include <math.h>
using namespace std;

int binarysearch(vector<int> array, int target) {
    int l = 0;
    int h = array.size() - 1;
    while (l <= h) {
        int mid = floor((l + h) / 2);
        if (target == array[mid]) return mid;
        if (target < array[mid]) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}