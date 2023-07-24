#include <iostream>
#include <vector>
using namespace std;


bool check(vector<int> a, int n) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == n) return false;
    }
    return true;
}

bool distinct(int n) {
    vector<int> vector;
    if ((n % 10) == n) return true;
    while (n != 0) {
        if (check(vector, n % 10)) {vector.push_back(n % 10);}
        else return false;
        n -= n % 10;
        n /= 10;
    }
    return true;
}


int main() {
    int n;
    cin >> n;
    n++;
    while(!distinct(n)) {
        n++;
    }
    cout << n << endl;
}