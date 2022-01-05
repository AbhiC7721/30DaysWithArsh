#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool canPair(vector<int> nums, int k) {
        	int n =  nums.size();
        	map<int, int>mp;
        	if(n%2)
        		return false;
        	for(int i=0; i<n; i++){
        		mp[((nums[i]%k)+k)%k]++;
        	}

        	for(int i=0; i<n; i++){
               int r = ((nums[i]+k)%k+k)%k;
               if(2*r==k){
               		if(mp[r]%2==1)
               			return false;
               }
               else if(r==0){
               		if(mp[0]%2==1)
               			return false;
               }
               else if(mp[r]!=mp[k-r])
            		return false; 
            }

            return true;
        }
           
};


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
    	int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) 
        	cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
   }
 return 0;
}