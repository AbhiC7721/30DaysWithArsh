/*
	Problem => Number of provinces
	Problem Link => https://leetcode.com/problems/number-of-provinces/
*/

class Solution {
public:
    
    // use dfs to check all the connected components of the graph and find the number of connected components
    // don't use bfs, not applicable here 
    
    void dfs(vector<vector<int>>&isConnected, vector<bool>&visited, int i, int n){
        visited[i] = true;
        for(int j=0; j<n; j++){
            if(isConnected[i][j]==1 && !visited[j])
                dfs(isConnected, visited, j, n);     
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>visited(n, false);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(isConnected, visited, i, n);
                count++;
            }
        }
        
        return count;
    }
    
};
