/*
1) Use DFS if we found any starting of island
We want to know the area of each connected shape in the grid, then take the maximum of these.
If we are on a land square and explore every square connected to it 4-directionally (and recursively squares connected to those squares, and so on), then the total number of squares explored will be the area of that connected shape.
To ensure we don't count squares in a shape more than once, let's make grid[i][col] = 0. It will also prevent us from counting the same shape more than once.

Complexity:
Time: O(M * N), where M is number of rows, N is number of columns in the grid.
Space: O(M * N), the space used by the depth stack during our recursion, in worst case is O(M * N).
*/
class Solution {
public:
    
    bool isValidRange(int current_row,int current_col, int total_rows, int total_cols){
        if(current_row < total_rows && current_col < total_cols && current_row >=0 && current_col >=0 )
            return true;
        return false;
    }
    
    void SearchDFS(vector<vector<int>>& grid, int cur_row, int cur_col, int& area, int total_rows, int total_cols){
    
        if(!isValidRange(cur_row,cur_col, total_rows, total_cols))
            return;
        
        if(grid[cur_row][cur_col] == 0)
            return;
        
        area++;
        grid[cur_row][cur_col] = 0;
        
        SearchDFS(grid,cur_row,cur_col -1 ,area,total_rows,total_cols); // Searching left cell
        
        SearchDFS(grid,cur_row -1 ,cur_col,area,total_rows,total_cols); // Searching top cell
        
        SearchDFS(grid,cur_row,cur_col + 1,area,total_rows,total_cols); // Searching right cell
        
        SearchDFS(grid,cur_row + 1, cur_col,area,total_rows,total_cols); // Searching bottom cell
            
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int largestAreaOfIsland = 0;
        
        for(int i = 0; i< rows; i++){
            for(int j = 0; j < cols;j++){
                
                if(grid[i][j] == 1){// found an island beginning
                    int areaOfIsland = 0;
                    SearchDFS(grid,i,j,areaOfIsland,rows,cols);
                    largestAreaOfIsland = max(largestAreaOfIsland, areaOfIsland);
                } 
                    
            }
        }
        
        return largestAreaOfIsland;
    }
};