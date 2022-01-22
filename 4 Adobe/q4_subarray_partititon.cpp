/*
	Problem => Partition Equal Subset Sum
	Problem Link => https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
*/

class Solution {
	int equalPartition(int N, int arr[]){
		int sum = 0
		for(int i=0; i<N; i++){
			sum += arr[i];
		}

		if(sum%2)
			return 0;
		sum/=2;
		vector<vector<int>>dp(N+1,)
	}
};