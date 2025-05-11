#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> t) {
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == 0 || t[i] == 1) return true;
    }
    return false;
}

// 0 -> left has, 1 -> right has, 2 -> none
void proc(vector<int>& ret, vector<int> a, vector<int> b) {
    for (int i = 0; i < ret.size(); i++) ret[i] = -1;
    for (int i = 0; i < a.size(); i++) {
        if (b[i] != a[i]) {
            if (i > 0 && b[i] == b[i - 1] && b[i - 1] == a[i - 1]) {
                ret[i - 1] = 0;
                while (i < a.size() && b[i] == b[i - 1] && a[i] != b[i]) {
                    ret[i] = 0;
                    i++;
                }
                i--;
                continue;
            } else {
                ret[i] = 1;
                int temp = i;
                i++;
                while (i < a.size() && b[i] == b[i - 1] && a[i] != b[i]) {
                    ret[i] = 1;
                    i++;
                }
                if (b[i] != b[i - 1] || b[i] != a[i]) {
                    i--;
                    for (int j = temp; j <= i; j++) ret[j] = 2;
                    continue;
                }
                if (a[i] == b[i]) {
                    ret[i] = 1;
                    continue;
                }
            }
        }
    }
}

// R = 82 L = 76
int main() {
    // input
    int N;
    vector<int> a, b;
    cin >> N;
    vector<vector<int>> ans;
    for (int i = 0; i < N; i++) {
        a.push_back(1);
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        b.push_back(1);
        cin >> b[i];
    }
    vector<int> t(N, -1);
    int l = 0, r = 0, temp = -1;
    proc(t, a, b);
    while (check(t)) {
        proc(t, a, b);
        for (int i = 0; i < N; i++) {
            if (t[i] == 1) {
                l = i;
                while (i < N && a[i] != b[i]) {
                    if (l > 0 && b[l - 1] == a[i]) temp = i;
                    i++;
                }
                r = i;
                if (r == l) continue;
                if (temp != -1) {
                    for (int j = l; j <= temp; j++) {
                        b[j] = b[l - 1];
                    }
                    for (int j = temp + 1; j <= r; j++) {
                        b[j] = a[j];
                    }
                    temp = -1;
                } else {
                    for (int j = l; j <= r; j++) {
                        b[j] = a[j];
                    }
                }
                ans.insert(ans.begin(), {76, l, r});
                i--;
            } else if (t[i] == 0) {
                l = i;
                i++;
                while (i < N && b[i] == b[i - 1]) {
                    i++;
                }
                r = i - 1;
                if (r == l) {
                    i--;
                    continue;
                }
                i = l + 1;
                while (i < N && b[i] == b[i - 1]) {
                    if (r + 1 < N && a[i] == b[r + 1]) {
                        temp = i;
                        break;
                    }
                    i++;
                }
                if (temp != -1) {
                    for (int j = l; j < temp; j++) {
                        b[j] = a[j];
                    }
                    for (int j = temp; j <= r; j++) {
                        b[j] = b[r + 1];
                    }
                    temp = -1;
                } else {
                   for (int j = l; j <= r; j++) {
                        b[j] = a[j];
                   } 
                }
                i = r - 1;
                ans.insert(ans.begin(), {82, l, r});
            }

        }
    }
    for (int i = 0; i < N; i++) {
        if (a[i] != b[i]) {cout << "NO"; return 0;} 
    }

    cout << "YES\n";
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        char ch = static_cast<char>(ans[i][0]);
        cout << ch << " " << +ans[i][1] << " " << +ans[i][2] << "\n";
    }
}