/*
	Problem => Stickler Thief
	Problem Link => https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/
*/

class Solution {
	public:
		int FindMaxSum(int arr[], int n){
			vector<int>dp(n, 0);
			if(n==1)
				return arr[0];
			dp[0] = arr[0];
			dp[1] = arr[1];

			for(int i=2; i<n; i++){
				dp[i] = max(dp[i-1], dp[i-2]+arr[i]);
			}

			return dp[n-1];
		}
};