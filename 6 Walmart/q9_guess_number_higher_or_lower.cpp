/*
    Problem => Guess Number higher or lower
    Problem Link => https://leetcode.com/problems/guess-number-higher-or-lower-ii 
*/

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int l=2; l<=n; l++){
            for(int start=0; start<=n-l; start++){
                int end = start + l;
                for(int i=start; i<end; i++){
                    int num = i+1;
                    if(i==start)
                        dp[start][end] = num + dp[start+1][end];
                    else
                        dp[start][end] = min(dp[start][end], max(dp[start][i], dp[i+1][end])+num);
                }
            }
        }
        
        return dp[0][n];
    }
};