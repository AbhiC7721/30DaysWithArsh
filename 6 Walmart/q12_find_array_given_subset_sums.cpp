/*
	Problem => Find array given subset sums
	Problem Link => https://leetcode.com/problems/find-array-given-subset-sum 
*/

class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        sort(sums.begin(), sums.end());
        vector<int>ans;
        for(int i=0; i<n; i++){
            int dif = sums[1]-sums[0];
            vector<int>subset1, subset2;
            map<int, int>mp;
            bool found = false;
            for(int j=0; j<sums.size(); j++){
                if(mp[sums[j]]==0){
                    subset1.push_back(sums[j]);
                    mp[sums[j]+dif]++;
                    if(sums[j]==0)
                        found = true;
                }
                else{
                    subset2.push_back(sums[j]);
                    mp[sums[j]]--;
                }
            }
            
            if(found){
                ans.push_back(dif);
                sums = subset1;
            }
            else{
                ans.push_back(-dif);
                sums = subset2;
            }
        }
        
        return ans;
    }
};