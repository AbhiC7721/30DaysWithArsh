/*
	Stock span problem
	Problem Link => https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

*/

class Solution {
	public:
	vector <int> calculateSpan(int price[], int n)
    {
    	stack<int>s;
        s.push(0);

        vector<int>ans(n);
        ans[0] = 1;

        for(int i=1; i<n; i++){
           int prev = 1;
           while((i-prev)>=0 && price[i]>=price[i-prev])
                prev += ans[i-prev];
           ans[i] = prev;
       }

       return ans;
    }
}