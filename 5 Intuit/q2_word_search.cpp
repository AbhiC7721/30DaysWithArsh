/*
	Problem => Word Search
	Problem Link => https://practice.geeksforgeeks.org/problems/word-search/1/
*/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    
    bool dfs(vector<vector<char>>&board, int i, int j, string word, int pos, vector<vector<bool>>&visited){
        
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size())
            return false;
        if(pos==word.length())
            return true;
        bool left, right, up, down; 
        if(word[pos]==board[i][j] && !visited[i][j]){
             visited[i][j] = true;
             left = dfs(board, i, j-1, word, pos+1, visited);
             up = dfs(board, i-1, j, word,  pos+1, visited);
             down = dfs(board, i+1, j, word, pos+1, visited);
             right = dfs(board, i, j+1, word, pos+1, visited);
             visited[i][j] = false;
             return left || right || up || down;
        }
        else
            return false;
        
    }

    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0] && !visited[i][j]){
                    if(dfs(board, i, j, word, 0, visited))
                        return true;
                    visited[i][j] = false;
                }
            }    
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends