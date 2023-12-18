/**
 * Question:
Three players A,B,C are playing a game.
Each player starts by occupying a cell in R*C matrix and name it A,B,C Respectively.
The player which is able to occupy maximum rectangular area in the grid is the winner.
Return the winner.

Observations/Questions asked by me:
Can there be more than 3 players? - No
Can there be a case where only 2 players are able to occupy the matrix. Eg: We didnt find any matrix with "C" only "A" and "B" are the value.
Minimum area by any player would be 1, if its present.(ie only occupying single cell)

Proposed Solution:
1) Use DFS start from a matrix and do dfs. At max there would be 3 dfs for "A", "B" and "C".
2) The DFS should return me the max area for that point.

Imp things to wonder inside the problem:
1) How do we compute the area from index (i, j). Ans = by updating the area index(but how)
2) If you find a rectangle, how would you verify if its a valid rectangle. (Asked as a follow up)
lets say you get i,j and x,y two endings on preceding diagnol. How you gona verify if its a valid rectangle.

My Code:

*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool outOfBounds(int i, int j, vector<vector<string>> grid){
    return false;
}

// i,j being the starting points and x,y being the last points of preceding diagnol
bool isValidRectange(int i, int j, int x, int y){
    // Implement logic of validating if its a valid triangle or not
}

void DFS(string ch, vector<vector<string>> grid, int i, int j, int area){
    if(!outOfBounds(i, j, grid) || grid[i][j] != ch)
        return;
    grid[i][j] = "X"; // So that we dont come to this again

    // if(isValidRectange(i+1, j)) // if its valid then only call the next recursion
    DFS(ch, grid, i+1, j, area);
    DFS(ch, grid, i - 1, j, area);
    DFS(ch, grid, i, j + 1, area);
    DFS(ch, grid, i, j - 1, area);

    grid[i][j] = "X";
}

int winnerOfGame(const vector<vector<string>> grid){
    int rows = grid.size();
    int cols = grid[0].size();

    vector<int> maxArea = {0,0,0}; // storing max area of A,B and C respectively.

    for(int i = 0; i< rows; i++){
        for(int j = 0; j< cols;j++){
            int area = 1;
            string player = grid[i][j];
            maxArea["A" - "A"] = 1;
            DFS(player, grid, i, j, area);

        }
    }
}

int main(){
    vector<vector<string>> mat{
        {"A", "B", "C"},
        {"B", "A", "B"},
        {"B", "C", "B"},
    };

    int winner =  winnerOfGame(mat);

    return 0;
}