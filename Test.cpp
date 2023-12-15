#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        return recursive(heights);
    }

    int recursive(vector<int> heights) {
        if (heights.size() == 0) return 0;
        if (heights.size() == 1) return heights[0];
        int min = INT_MAX;
        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] < min) min = heights[i];
        }
        vector<int> temp;
        int counter = 0;
        int max = min * heights.size();
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] == min) {
                if (temp.size() != 0) {
                    int results = recursive(temp);
                    temp = {};
                    if (results > max) max = results;
                }
            } else {
                temp.push_back(heights[i]);
            }
        }
        if (temp.size() != 0) {
            int results = recursive(temp);
            if (results > max) max = results;
        }
        return max;
    }
};

int main() {
    Solution solution; 
    vector<int> heights = {2, 2, 2, 1, 3, 4, 5, 1, 4, 1, 5, 1, 11, 1};
    cout << solution.largestRectangleArea(heights);
}