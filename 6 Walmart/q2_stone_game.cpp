/*
    Problem Link => https://leetcode.com/problems/stone-game/
    Pronblem => Stone Game
*/

class Solution {
public:
    int stoneGameDp(vector<int>&piles, int i, int j, int ch, vector<vector<int>>&dp){
        if(i>=piles.size() || j<0)
           return 0;
        if(i>j)
            return dp[i][j] = 0;
        else if(dp[i][j]!=INT_MAX)
            return dp[i][j];
        if(ch%2==0)
            dp[i][j] = max( (piles[i]+stoneGameDp(piles, i+1,j, ch+1, dp)), (piles[j]+stoneGameDp(piles, i, j-1, ch+1, dp)) );
        else
            dp[i][j] = min( -piles[i]+stoneGameDp(piles, i+1,j, ch+1, dp), -piles[j]+stoneGameDp(piles, i,j-1, ch+1, dp) );
        
        return dp[i][j];
            
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int ch = 0;
        vector<vector<int>>dp(n+1, vector<int>(n+1, INT_MAX));
        stoneGameDp(piles, 0, n-1, ch, dp);
//         for(int i=0; i<n+1; i++){
//             for(int j=0; j<n+1; j++){
//                 cout<<dp[i][j]<<" ";
//             }
            
//             cout<<"\n";
//         }
        return dp[0][n-1]>0;
        
        return true;
    }
};
