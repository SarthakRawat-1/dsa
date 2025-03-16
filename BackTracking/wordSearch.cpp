// Problem Statement :- https://leetcode.com/problems/word-search/description/

// Whenever we visit a character which satisfies the condition, we will change it with some character like $.
// As soon as we are not able to find the match, we will backtrack and change the $ character back to its original character.
// Thene explore a new direction to find the characters of the word.
// Once we have found the word, we will return true. 

#include <bits/stdc++.h>
using namespace std;

// Possible directions to move (right, left, down, up)
vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// Helper function to recursively search for the word in the grid
bool find(vector<vector<char>>& board, int i, int j, int index, string& word) {

    // Base case: if we have matched the entire word, return true
    if (index == word.length()) {
        return true;
    }

    // Boundary and condition checks:
    // 1. Check if the current indices are out of bounds.
    // 2. Check if the character in the board does not match the current character in the word.
    // 3. Check if the cell is already visited (marked as '$').
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index] || board[i][j] == '$') {
        return false;
    } 

    // Temporarily mark the current cell as visited by setting it to '$'
    char temp = board[i][j];
    board[i][j] = '$';

    // Recursively search in all four possible directions
    for (auto &dir : directions) {
        int new_i = i + dir[0];
        int new_j = j + dir[1];

        // If the next cell in any direction leads to a solution, return true
        if (find(board, new_i, new_j, index + 1, word)) {
            return true;
        }
    }

    // Backtrack: revert the current cell to its original character
    board[i][j] = temp;
    return false;
}

// Main function to check if the word exists in the board
bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();       // Number of rows in the board
    int m = board[0].size();    // Number of columns in the board

    // Traverse each cell of the board as a potential starting point for the word
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If the first character matches and `find` returns true, the word exists in the board
            if (board[i][j] == word[0] && find(board, i, j, 0, word)) {
                return true;
            }
        }
    }

    // If no valid path is found, return false
    return false;
}

int main() {
    // Example grid and word to search
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";

    // Check if the word exists in the board
    if (exist(board, word)) {
        cout << "Word found!" << endl;
    } else {
        cout << "Word not found." << endl;
    }

    return 0;
}
