/*  Maximum Profit problem- leetcode problem 
	Link - https://practice.geeksforgeeks.org/problems/maximum-profit4657/1
*/

class Solution {
	public:
		int maxProfit(int k, int n, vector<int>price){
			vector<vector<int>>profit(k+1, vector<int>(n+1, 0));

			 for(int i=1; i<=k; i++){
			 	int prev = INT_MIN;
			 	for(int j=1; j<=n; j++){
			 		prev = max(prev, profit[i-1][j-1] - price[j-1]);
			 		profit[i][j] = max(profit[i][j-1], price[j] + prev);
			 	}
			 }

			 return prfoit[k][n-1];
		} 
};

// Complexity => O(n*k)
// It is reduced from O(n*n*k) as we calculate the prev from the precalculated steps
