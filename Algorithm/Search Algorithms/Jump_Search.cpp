#include <cmath>
using namespace std;

int jumpSearch(int array[], int size, int key) {
    int start = 0;
    int end = sqrt(size);

    while(array[end] <= key && end < size) {
        start = end;
        end += sqrt(size);
        if(end > size - 1) end = size;
    }

    for(int i = start; i < end; i++) {
        if(array[i] == key) return i;
    }
    return -1;
}