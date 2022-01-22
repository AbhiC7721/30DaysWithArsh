/*
	Problem Link => Subarray sum
	Problem Link => https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
*/

class Solution {
public:
	vector<int> subarraySum(int arr[], int n, long long s){
		int start = 0, end = 0, curSum = 0;
		while(end<=n-1){
			curSum += arr[end];
			if(curSum==s){
				return {start+1, end+1};
			}
			while(curSum>s){
				curSum -= arr[start];
				start++;
				if(curSum==s)
					return {start, end+1};
			}

			end++;
		}

		return {-1};
	} 
};