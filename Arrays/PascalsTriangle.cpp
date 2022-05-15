#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      
        vector<vector<int>> triangle(numRows);
        
        for(int row = 0; row<numRows; row++){
            
            triangle[row].resize(row+1);
            triangle[row][0] = triangle[row][row] = 1; // Adding 1 to first and last index
            // No need to decrement triangle[row][row-1] as we are already taking 0 based indexing. Thus,3rd row = T[2] and T[2][0] = T[2][2]
            
            // Traversing from 1st column to 2nd last column
            for(int col = 1; col < row; col++){
                triangle[row][col] = triangle[row-1][col-1] + triangle[row-1][col];
            }
            
        }
        
        return triangle;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--){
        Solution obj;
        int n;
        cin >> n;
        vector<vector<int>> res = obj.generate(n);

        for (int i = 0; i < res.size(); i++){
            for(int j = 0; j<res[i].size(); j++)
                cout<<res[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}