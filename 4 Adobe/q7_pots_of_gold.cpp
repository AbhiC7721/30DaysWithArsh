//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    
    int dp[501][501];
    
    int maxCoinsDP(vector<int>&arr, int start, int end){
        if(start==end)
            return dp[start][end] = arr[start];
        else if(start>end)
            return dp[start][end] = 0;
        else if(dp[start][end]!=-1)
            return dp[start][end];
            
        // arr[start] or arr[end] is selected
        // next choice will be to minimize whatever Y chooses
        // X chooses arr[start], then y chooses => 
        //                                  arr[start+1] + arr[start+2..end]
        //                                  arr[end] +  arr[start+1..end-1])
        // Y chooses arr[end], then y chooses =>
        //                                  arr[end-1] + arr[start..end-2]
        //                                  arr[start] + arr[start+1..end-1]
        int choiceStart = arr[start] + min(maxCoinsDP(arr, start+2, end), maxCoinsDP(arr, start+1,end-1));
        int choiceEnd = arr[end] + min(maxCoinsDP(arr, start, end-2), maxCoinsDP(arr, start+1, end-1));
        dp[start][end] = max(choiceStart, choiceEnd);
        return dp[start][end];
    }
    
    
    int maxCoins(vector<int>&arr,int n)
    {
	    memset(dp, -1, sizeof(dp));
	    return maxCoinsDP(arr, 0, n-1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends