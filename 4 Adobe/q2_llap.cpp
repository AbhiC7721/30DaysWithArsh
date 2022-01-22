/*
	Problem => Longest length Arithmetic Progression
	Problem Link => https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1/
*/

class Solution{
public:
	int lengthOfLongestAP(int A[], int n){
		int ans = 0;
		if(n==1)
			return 1;
		vector<vector<int>>dp(n, vector<int>(10003));
		
		// visiting all elements of array with the first element as A[i]
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				int dif = nums[j]-nums[i];
				// dp[j][dif] is maximum of dp[i][dif]+1 or only jth and its previous element
				// whatever it is
				dp[j][dif] = max(dp[i][dif]+1, 2);
				ans = max(ans, dp[j][dif]);
			}
		}

		return ans;

	}
};