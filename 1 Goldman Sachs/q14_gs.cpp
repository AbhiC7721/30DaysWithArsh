class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n+1, 0);
        for(int i=1; i<=n; i++)
        	prefix[i] = nums[i-1] + prefix[i-1];
        int l,r, sum;
        for(int k=0; k<n; k++){
        	for(int i=0; i+k<n; i++){
                l = i, r = i+k;
                sum = prefix[r+1] - prefix[l];
                if(sum>=target)
                    return k+1;
            }
        }
        
        return 0;
    }
};