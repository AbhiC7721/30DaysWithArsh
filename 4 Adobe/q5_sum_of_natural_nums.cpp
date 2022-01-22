// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
    int helper(int sum, int x, int base){
        
        int powered = pow(base, x);
        if(sum == powered)
            return 1;
        if(sum < powered)
            return 0;
        
        int include = helper(sum-powered, x, base+1);
        int not_include = helper(sum, x, base+1);
        
        return include+not_include;
    }
    
    int numOfWays(int n, int x)
    {
        int ans = helper(n, x, 1);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}