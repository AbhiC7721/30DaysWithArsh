/*
    Problem => Maximum height tree
    Problem Link => https://practice.geeksforgeeks.org/problems/maximum-height-tree4803/1/ 
*/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int height(int N){
        int x = sqrt(1 + 8*N);
        x -=1;
        x/=2;
        return x;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.height(N)<<endl;
    }
    return 0;
}  // } Driver Code Ends