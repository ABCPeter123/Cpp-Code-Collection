#include <vector>
#include <math.h>
using namespace std;

int binarysearch(vector<int> array, int low, int high, int target) {
    if (low == high) {
        if (array[low] == target) return low;
        else return -1;
    }
    else {
        int mid = floor((low + high) / 2);
        if (target == array[mid]) return mid;
        else if (target < array[mid]) {
            return binarysearch(array, low, mid - 1, target);
        } else {
            return binarysearch(array, mid + 1, high, target);
        }
    }
}