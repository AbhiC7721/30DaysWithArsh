/*
    Problem => Largest NUmber in k swaps
    Problem Link => https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1/n
*/

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    
    void maxRecursive(string str, int n, int k, int c, string&ans){
        if(k==0)
            return;
            
        char maxi = str[c];
            for(int j=c+1; j<n; j++){
                if(maxi < str[j])
                    maxi = str[j];
            }
            
            if(maxi != str[c])
                k--;
            for(int j=n-1; j>=c; j--){
                if(str[j]==maxi){
                    swap(str[c], str[j]);
                    
                    if(str>ans)
                        ans = str;
                    maxRecursive(str, n, k, c+1, ans);
                    swap(str[c], str[j]);
                }
            }
    }
    
    string findMaximumNum(string str, int k)
    {   
       int n = str.size();
       string ans= str;
       maxRecursive(str, n, k,0,ans);
       
       return ans;
       
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends