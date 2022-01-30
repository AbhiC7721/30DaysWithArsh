/*
Problem => Number of unique paths
Problem Link => https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1/
*/

//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        vector<vector<int>>matrix(a, vector<int>(b, 0));
        for(int i=0; i<a; i++)
            matrix[i][0] = 1;
        for(int i=0; i<b; i++)
            matrix[0][i] = 1;
        for(int i=1; i<a; i++){
            for(int j=1; j<b; j++){
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
            }
        }
        
        return matrix[a-1][b-1];
    }
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends