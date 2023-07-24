#include <vector>
using namespace std;

vector<int> merge(vector<int> l1, vector<int> l2) {
    vector<int> final = {};
    while (l1.size() != 0 && l2.size() != 0) {
        if (l1[0] < l2[0]) {
            final.push_back(l1[0]);
            l1.erase(l1.begin());
        } else {
            final.push_back(l2[0]);
            l2.erase(l2.begin());
        }
    }

    if (l1.size() != 0) {
        for (auto i : l1) final.push_back(i);
    } else if (l2.size() != 0) {
        for (auto i : l2) final.push_back(i);
    }

    return final;
}

vector<int> merge_sort(vector<int> list) {
    if (list.size() == 1) return list;

    int mid_idx = list.size() / 2;
    vector<int> left = {};
    vector<int> right = {};
    for (int i = 0; i < mid_idx; i++) {
        left.push_back(list[i]);
    }
    for (int i = mid_idx; i < list.size(); i++) {
        right.push_back(list[i]);
    }

    left = merge_sort(left);
    right = merge_sort(right);
    vector<int> final = merge(left, right);

    return final;
}