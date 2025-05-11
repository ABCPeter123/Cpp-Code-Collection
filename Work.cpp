#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
   int val;
    TreeNode *left;
    TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        
    }
};


/**
1 9 1 4 10 4
7 10 6 3 4 5
2 8 3 4 7 6
8 1 9 1 3 3

1 9 1 4 10 4
7 10 6 4 4 5
2         6
8 1 9 1 3 3

 */


int main() {
    Solution solution;
    vector<int> s = {8,17,14,8,14,12,16,11,4,14,19,6,8,8,2,10,2,1,1,18};
    for (auto i : solution.countVisitedNodes(s)) cout << i << endl;

}