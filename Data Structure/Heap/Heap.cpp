#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
class MaxHeap {
    int size = 3;
    int* array = new int[size];
    int last_index = 0;

    public:
    int get_lastindex() {
        return last_index;
    }
    void insert(int value) {
        if (last_index >= size) {
            int* new_arr = new int[size * 2];
            for (int i = 0; i < size; i++) {
                new_arr[i] = array[i];
            }
            array = new_arr;
            size = size * 2;
        }
        array[last_index] = value;
        shift_up();
        last_index++;
    }    

    void swap(int index1, int index2) {
        int temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }

    int get_parent(int number) {return floor((number - 1) / 2);}

    int get_leftchild(int number) {return (2 * number + 1);}

    int get_rightchild(int number) {return (2 * number + 2);}

    void shift_up() {
        int index_temp = last_index;
        while (index_temp >= 0) {
            int parent_index = get_parent(index_temp);
            if ((parent_index >= 0) && (array[parent_index] < array[index_temp])) {
                swap(parent_index, index_temp);
                index_temp = parent_index;
            } else break;
        }
    }

    int del() {
        swap(last_index - 1, 0);
        last_index--;
        int index_temp = 0;
        while (index_temp < last_index) {
            int maxval = array[index_temp];
            int maxindex = index_temp;

            int indexleftchild = get_leftchild(index_temp);
            if ((indexleftchild < last_index) && (array[indexleftchild] > maxval)) {
                maxval = array[indexleftchild];
                maxindex = indexleftchild;
            }

            int indexrightchild = get_rightchild(index_temp);
            if ((indexrightchild < last_index) && (array[indexrightchild] > maxval)) {
                maxval = array[indexrightchild];
                maxindex = indexrightchild;
            } 

            if (maxindex == index_temp) break;
            swap(maxindex, index_temp);

            index_temp = maxindex;
        }
        return array[last_index];
    }

    void print() {
        cout << "heap: ";
        for (int i = 0; i < last_index; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

class MinHeap {
    int size = 3;
    int* array = new int[size];
    int last_index = 0;

    public:
    int get_lastindex() {
        return last_index;
    }
    void insert(int value) {
        if (last_index >= size) {
            int* new_arr = new int[size * 2];
            for (int i = 0; i < size; i++) {
                new_arr[i] = array[i];
            }
            array = new_arr;
            size = size * 2;
        }
        array[last_index] = value;
        shift_up();
        last_index++;
    }    

    void swap(int index1, int index2) {
        int temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }

    int get_parent(int number) {return floor((number - 1) / 2);}

    int get_leftchild(int number) {return (2 * number + 1);}

    int get_rightchild(int number) {return (2 * number + 2);}

    void shift_up() {
        int index_temp = last_index;
        while (index_temp >= 0) {
            int parent_index = get_parent(index_temp);
            if ((parent_index >= 0) && (array[parent_index] > array[index_temp])) {
                swap(parent_index, index_temp);
                index_temp = parent_index;
            } else break;
        }
    }

    int del() {
        swap(last_index - 1, 0);
        last_index--;
        int index_temp = 0;
        while (index_temp < last_index) {
            int minval = array[index_temp];
            int minindex = index_temp;

            int indexleftchild = get_leftchild(index_temp);
            if ((indexleftchild < last_index) && (array[indexleftchild] < minval)) {
                minval = array[indexleftchild];
                minindex = indexleftchild;
            }

            int indexrightchild = get_rightchild(index_temp);
            if ((indexrightchild < last_index) && (array[indexrightchild] < minval)) {
                minval = array[indexrightchild];
                minindex = indexrightchild;
            } 

            if (minindex == index_temp) break;
            swap(minindex, index_temp);

            index_temp = minindex;
        }
        return array[last_index];
    }

    void print() {
        cout << "heap: ";
        for (int i = 0; i < last_index; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap heap;
    heap.insert(1);
    heap.insert(3);
    heap.insert(2);
    heap.insert(4);
    heap.print();
    cout << "Deleted number: " << heap.del() << endl;
    heap.print();

    MaxHeap heap1;
    heap1.insert(1);
    heap1.insert(3);
    heap1.insert(2);
    heap1.insert(4);
    heap1.print();
    cout << "Deleted number: " << heap1.del() << endl;
    heap1.print();
}