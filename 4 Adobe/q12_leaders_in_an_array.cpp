/*	
	Problem => Leaders in an Array
	Problem Link => https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1/
*/

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
    	int maxi = a[n-1];
        int max_pos = n-1;
        vector<int>ans;
        ans.push_back(a[n-1]);
        for(int i=n-2; i>=0; i--){
        	if(maxi <= a[i]){
                max_pos = i;
                maxi = a[i];
            }
            if(max_pos == i)
                ans.push_back(a[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

};
