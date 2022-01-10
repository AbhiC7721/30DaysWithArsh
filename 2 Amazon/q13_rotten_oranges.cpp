/*
     problem => Rotten Oranges
     Problem Link => https://leetcode.com/problems/rotting-oranges/
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int, int>>>q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==2)
                    q.push({0, {i, j}});
            }
        }
        
        int time = 0, temp=0;
        // grid[i-1][j], grid[i+1][j], grid[i][j-1], grid[i][j+1]
        while(!q.empty()){
            pair<int, pair<int, int>>frnt = q.front();
            temp = frnt.first;
            int i = frnt.second.first;
            int j = frnt.second.second;
            
            //top
            if(i-1>=0){
                if(grid[i-1][j]==1){
                    grid[i-1][j] = 2;
                    q.push({temp+1, {i-1, j}});
                }
            }
            
            //bottom
            if(i+1<n){
                if(grid[i+1][j]==1){
                    grid[i+1][j] = 2;
                    q.push({temp+1, {i+1, j}});
                }
            }
            
            //left
            if(j-1>=0){
                if(grid[i][j-1]==1){
                    grid[i][j-1] = 2;
                    q.push({temp+1, {i, j-1}});
                }
            }
            
            //right
            if(j+1<m){
                if(grid[i][j+1]==1){
                    grid[i][j+1] = 2;
                    q.push({temp+1, {i, j+1}});
                }
            }
            
            q.pop();
            
        }
        
        int ans = temp;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    ans = -1;
                    break;
                }
            }
        }
        
        
        return ans;
    }
};

// Time complexity => o(m*n)
