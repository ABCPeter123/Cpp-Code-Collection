#include <iostream>
#include <cmath>
using namespace std;

int translated_coord(int m, int x) {
    int exp = pow(5, m - 1);
    return (int) floor(x / exp);
}

int middle_x(int m, int x) {
    for (int k = 1; k < m; k++) {
        int temp = 5 * x + 2;
        x = temp;
    }
    return x;
}

int main() {
    int t;
    cin >> t;
    int array[t];
    bool have = false;
    int  m, x, y;
    int new_x, new_y;
    int i = 0;
    while (i < t) {
        have = false;
        cin >> m >> x >> y;
        if (m != 1) {
            new_x = translated_coord(m, x);
            new_y = translated_coord(m, y);
        } else {new_x = x; new_y = y;}
        
        if (((new_x == 1)  && (new_y == 0)) || ((new_x == 2) && (new_y == 0)) || ((new_x == 2) && (new_y == 1)) || ((new_x == 3) && (new_y == 0))) {
            have = true;
        } else if ((((new_x == 1)  && (new_y == 1)) || ((new_x == 2) && (new_y == 2)) ||  ((new_x == 3) && (new_y == 1))) && (m != 1)) {
            bool end = false;
            int temp_m = m;
            int y1 = y;
            int x1 = x;
            while (!end && (temp_m != 0)) {
                for (int j = 1; j <= 3; j++) {
                    int temp = ((pow(5, temp_m - 1) - 1) / 2);
                    if (((x1 + 1) == middle_x(temp_m, j)) || ((x1 - 1) == middle_x(temp_m, j))) {
                        new_y = translated_coord(temp_m, y1 - temp + 1);
                    } else if (x1 == middle_x(temp_m, j)) {
                        new_y = translated_coord(temp_m, y1 - temp);
                    } else continue;

                    if (((new_x == 1)  && (new_y == 0)) || ((new_x == 2) && (new_y == 0)) || ((new_x == 2) && (new_y == 1)) || ((new_x == 3) && (new_y == 0))) {
                        end = true;
                        have = true;
                        break;
                    }
                }
                y1 = (int) floor(y1 / 5);
                x1 = (int) floor(x1 / 5);
                if (temp_m - 1 != 0) new_x = translated_coord(temp_m - 1, x1);
                temp_m--;
            }
            
        }

        if (have) {
            array[i] = 1;
        } else {array[i] = 0;}

        i++;
    }
    string output;
    for (int i = 0; i < t; i++) {
        if (array[i] == 1) {
            cout << "crystal" << endl;
        } else cout << "empty" << endl;
    }

    return 0;
}