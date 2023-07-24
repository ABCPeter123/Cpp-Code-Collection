#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
    int capacity;
    list<int> *table;

    public:
        bool checkPrime(int n) {
            int i;
            if (n == 1 || n == 0) return false;
            for(i = 2; i < n / 2; i++) {
                if (n % i == 0) return false;
            }
            return true;
        }

        int getPrime(int n) {
            if (n % 2 == 0) n++;
            while (!checkPrime(n)) n += 2;
            return n;
        }

        int hashFunction(int data) {
            return (data % capacity);
        }

        HashTable(int c) {
            int size = getPrime(c);
            this->capacity = size;
            table = new list<int>[capacity];
        }

        void insertItem(int data) {
            int index = hashFunction(data);
            table[index].push_back(data);
        }

        void deleteItem(int data) {
            int index = hashFunction(data);
            list<int>::iterator i;
            for (i = (table[index]).begin(); i != table[index].end(); i++) {
                if (*i == data) break;
            }
            if (i != table[index].end()) table[index].erase(i);
        }

        void displayHash() {
            for (int i = 0; i < capacity; i++) {
                cout << "table[" << i << "]";
                for (auto x : table[i]) cout << "-->" << x;
                cout << endl;
            }
        }
};

int main() {
    int data[] = {124, 425, 123, 231, 324, 111};
    int size = sizeof(data) / sizeof(data[0]);
    HashTable hash(size);
    for (int i = 0; i < size; i++) hash.insertItem(data[i]);
    hash.displayHash();
    hash.deleteItem(124);
    cout << endl;
    hash.displayHash();
    return 0;
}