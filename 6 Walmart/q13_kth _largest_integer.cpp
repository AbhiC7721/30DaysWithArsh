/*	
	Problem => kth largest integer in array
	Problem Link => https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/
*/

class Solution {
public:
    
    static bool compare(string &a, string &b){
        if(a.size()!=b.size())
            return a.size()>b.size();
        else
            return a>b;
        // no need to use for loop here as equal length strings can be compared lexicgraphically
    }
    
    string kthLargestNumber(vector<string>& nums, int k) {
        // cout<<nums.size()<<" ";
        sort(nums.begin(), nums.end(), compare);
        for(auto it: nums)
            cout<<it<<" ";
        return nums[k-1];
    }
};