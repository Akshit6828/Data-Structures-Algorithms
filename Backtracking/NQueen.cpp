#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool checkLeftUpperDiagnol(int row, int col,vector<string> &board, int n){
    
    // Checking left - upper diagnol of the current coordinates

    while(row >=0 && col >=0){
        if(board[row][col] =='Q')
            return false;
        row--;
        col--;
    }
    return true;
}

bool checkLeft(int row, int col,vector<string> &board, int n){
    while(col >= 0){
        if(board[row][col] =='Q')
            return false;
        col--;
    }

    return true;
}

bool checkLeftDown(int row, int col,vector<string> &board, int n){
    while(row<n && col>=0 ){
        if(board[row][col] =='Q')
            return false;
        row++;
        col--;
    }
    return true;
}

bool isSafeToPlaceQueen(int row, int col,vector<string> &board, int n){

    if(checkLeftUpperDiagnol(row,col,board,n) && checkLeft(row,col,board,n) && checkLeftDown(row,col,board,n))
        return true;
    return false;
    
}
void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
    
    // base case : if we reach the last column
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row = 0; row < n ; row++){
        if(isSafeToPlaceQueen(row,col,board,n)){
            board[row][col] = 'Q'; // placing the queen
            solve(col + 1, board, ans , n);
            board[row][col] = '.'; // Backtracking the placed queen to check if other options are possible
        }
    }

}


vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n ,'.');

    // Making a vector of strings each of '....' in the 
    for(int i = 0; i < n ; i++)
        board[i] = s;
    
    solve(0, board, ans , n);
    return ans;
    

}
int main(){
    int n;
    cin>>n;
    vector<vector<string>> arrangements = solveNQueens(n);

    for(auto i : arrangements){
        for(auto j : i){
            cout<<j<<endl;
        }
        cout<<endl;
    }
    return 0;
}