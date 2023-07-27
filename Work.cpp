#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool answer = false;
        vector<bool> temp(board[0].size(), false);
        vector<vector<bool>> check(board.size(), temp);
        vector<pair<int, int>> found;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (word.find(board[i][j]) == -1) check[i][j] = true;
                if (board[i][j] == word[0]) found.push_back(make_pair(i, j));
            }
        }
        for (int i = 0; i < found.size(); i++) {
            find(answer, 0, found[i], found[i], check, board, word);
            if (answer == true) return answer;
        }
        return answer;
    }

    void find(bool& found, int i, pair<int, int> grid, pair<int, int> prev, vector<vector<bool>> check, vector<vector<char>> board, string word) {
        int x = grid.first;
        int y = grid.second;
        if (board[x][y] != word[i]) return;
        if (i == word.size() - 1 && word[i] == board[x][y]) {
            found = true;
            return;
        }
        check[prev.first][prev.second] = true;
        vector<pair<int, int>> array;
        if (x >= 1 && board[x - 1][y] == word[i + 1] && check[x - 1][y] == false) array.push_back(make_pair(x - 1, y));
        if (y >= 1 && board[x][y - 1] == word[i + 1] && check[x][y - 1] == false) array.push_back(make_pair(x, y - 1));
        if (x < board.size() - 1 && board[x + 1][y] == word[i + 1] && check[x + 1][y] == false) array.push_back(make_pair(x + 1, y));
        if (y < board[0].size() - 1 && board[x][y + 1] == word[i + 1] && check[x][y + 1] == false) array.push_back(make_pair(x, y + 1));
        for (auto j : array) {
            find(found, i + 1, j, grid, check, board, word);
            if (found) return;
        }
        
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board = 
    {
    {'C', 'A', 'A'},
    {'A', 'A', 'A'},
    {'B', 'C', 'D'}
    };
    if(solution.exist(board, "AAB")) cout << "nice" << endl;
    else cout << "nah";
}
