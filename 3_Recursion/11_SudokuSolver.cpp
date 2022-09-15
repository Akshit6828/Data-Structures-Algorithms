#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void printBoard(vector<vector<char>>& board){
    for(auto row: board){
        for(auto element: row)
            cout<<element<<" ";
        cout<<endl;
    }
}

bool IsValidToPlace(char ch, vector<vector<char>> &board, int row, int col){
    
    for(int i = 0; i < 9; i++){
        // Check row
        if(board[row][i] == ch) return false;

        // Check col
        if(board[i][col] == ch) return false;

        // Check (3*3) matrix
        int x = 3 *(row/3) + i/3;
        int y = 3* (col/3) + i%3;
        if( board[x][y] == ch ) return false;
    }
    return true;
}
bool solve(vector<vector<char>>& board){
    // 1: Traverse through the entire board:
    for(int i = 0; i< board.size(); i++){
        for(int j = 0; j< board[0].size(); j++){

            // Check if we encouted a empty cell
            if(board[i][j] == '.'){

                // Check for char 1 - 9, which can be placed.
                for(char ch = '1' ; ch <='9'; ch++){

                    if(IsValidToPlace(ch, board, i, j)){
                        board[i][j] = ch;
                        // Storing current answer in a variable so that we can check if the current placed char takes us to the answer or not.
                        bool result = solve(board);
                        
                        if(result == true)
                            return true; // We found a valid answer. Lets return
                        else
                            board[i][j] = '.'; // Lets backtrack as the placed answer is not a valid one.
                    }
                }
                return false; // ie: No char is able to place, thus return false;
            }
        }
    }
    return true; // Return true, if already the board is completly filled
}


void solveSudoku(vector<vector<char>>& board) {
    solve(board);
    printBoard(board);
}

int main(){
    vector<vector<char>> board= { {'5','3','.','.','7','.','.','.','.'},
                                   {'6','.','.','1','9','5','.','.','.'},
                                   {'.','9','8','.','.','.','.','6','.'},
                                   {'8','.','.','.','6','.','.','.','3'},
                                   {'4','.','.','8','.','3','.','.','1'},
                                   {'7','.','.','.','2','.','.','.','6'},
                                   {'.','6','.','.','.','.','2','8','.'},
                                   {'.','.','.','4','1','9','.','.','5'},
                                   {'.','.','.','.','8','.','.','7','9'}
                                };

    solveSudoku(board);
    return 0;
}


/*

*/