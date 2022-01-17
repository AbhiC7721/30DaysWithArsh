/*
	Problem => Unit Area of Largest ones
	Problem Link => https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/#
*/

class Solution {
public:
    
    void dfs(vector<vector<int>>&grid, int i, int j, vector<vector<bool>>&visited, int&area){
        
        if(grid[i][j]==1){
            if(i-1>=0 && !visited[i-1][j] && grid[i-1][j]==1){
                visited[i-1][j] = true;
                area++;
                dfs(grid, i-1, j, visited, area);
            } 
            
            if(i-1>=0 && j-1>=0 && !visited[i-1][j-1] && grid[i-1][j-1]==1){
                visited[i-1][j-1] = true;
                area++;
                dfs(grid, i-1, j-1, visited, area);
            } 
            
            if(i-1>=0 && j+1<grid[0].size() && !visited[i-1][j+1] && grid[i-1][j+1]==1){
                visited[i-1][j+1] = true;
                area++;
                dfs(grid, i-1, j+1, visited, area);
            } 
            
            if(i+1<grid.size() && !visited[i+1][j] && grid[i+1][j]==1){
                visited[i+1][j] = true;
                area++;
                dfs(grid, i+1, j, visited, area);
            }   
            
            if(i+1<grid.size() && j-1>=0 && !visited[i+1][j-1] && grid[i+1][j-1]==1){
                visited[i+1][j-1] = true;
                area++;
                dfs(grid, i+1, j-1, visited, area);
            }  
            
            if(i+1<grid.size() && j+1<grid[0].size() && !visited[i+1][j+1] && grid[i+1][j+1]==1){
                visited[i+1][j+1] = true;
                area++;
                dfs(grid, i+1, j+1, visited, area);
            }  
            
             
            if(j+1<grid[0].size() && !visited[i][j+1] && grid[i][j+1]==1){
                visited[i][j+1] = true;
                area++;
                dfs(grid, i, j+1, visited, area);
            }    
            if(j-1>=0 && !visited[i][j-1] && grid[i][j-1]==1){
                visited[i][j-1] = true;
                area++;
                dfs(grid, i, j-1, visited, area);
            }  
            
            
        }    
        
        else
            return;
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        int area = 0;
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    visited[i][j] = true;
                    area++;
                    dfs(grid, i,j, visited, area);
                    ans = max(ans, area);
                    area = 0;
                }        
            }
        }
        
        return ans;
    }
};