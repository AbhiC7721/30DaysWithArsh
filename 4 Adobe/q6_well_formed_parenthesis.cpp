//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string>ans;
    
     void parenthesisRec(int i, int j, int n, string cur){
        if(i==n && j==n){
            ans.push_back(cur);
            return;
        }
        if(i<n)
            parenthesisRec(i+1, j, n,cur+"(");
        if(j<i)
            parenthesisRec(i, j+1, n, cur+")");
    }

    vector<string> AllParenthesis(int n) 
    {
        int i = 0, j = 0;
        parenthesisRec(0, 0, n, "");
        return ans;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends