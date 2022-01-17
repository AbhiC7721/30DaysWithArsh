/*
	Problem => 4 Sum
	Problem Link => https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1
*/

typdef long long ll;

class Solution {
	public: 
		vector<vector<int>>fourSum(vector<int>& nums, int target){

        set<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        ll sum;
        
        for(int i=0; i<n-3; i++)
        {
            if(i<0 && nums[i]==nums[i-1]) continue; //same values for index i are skipped (avoid duplicates)
            for(int j=i+1; j<n-2; j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue; //same values for index j are skipped (avoid duplicates)
                int left =j+1, right=n-1;
                while(left<right) //2 pointer technique
                {
                    sum = (ll)(nums[i] + nums[j]);
                    sum += (ll)(nums[left] + nums[right]);
                    if(sum>target)
                        right--;
                    else if(sum==target)
                    {
                        ans.insert({nums[i],nums[j], nums[left], nums[right]});
                        left++;
                    }
                    else
                        left++;
                }
            }
        }
        vector<vector<int>>res;
        for(auto it: ans)
            res.push_back(it);
   
        return res;
	}
};
