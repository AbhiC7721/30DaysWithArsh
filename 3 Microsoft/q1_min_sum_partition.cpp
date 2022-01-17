/*
	Problem => Matrix Rotate
	Problem Link => https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/
*/

#include<bits/stdc++.h>

using namespace std;

int minDifference(int arr[], int n){
    
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    // We use dp same as partition sunbset sum equal to half sum is possible or not

    vector<vector<int>>dp(n+1, vector<int>(sum+1));
    
    for(int i=0; i<n; i++)
        dp[i][0] = 1;
    
    for(int i=1; i<sum+1; i++)
        dp[0][i] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<sum+1; j++){
            
            if(j-arr[i-1] >=0)
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    int ans = 0;

    for(int j=sum/2; j>=0; j--){
        if(dp[n][j]==true)
            ans = sum - 2*j;
    }

    return ans;
    
}