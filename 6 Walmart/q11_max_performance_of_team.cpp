/*
	Problem => Max Performance of a team
	Problem Link => https://leetcode.com/problems/maximum-performance-of-a-team/
*/
const int MOD = 1000000007;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>>eng;
        for(int i=0; i<n; i++){
            eng.push_back({efficiency[i], speed[i]});
        }
        
        sort(eng.rbegin(), eng.rend());
        // for(auto it: eng)
        //     cout<<it.first<<" "<<it.second<<"\n";
        long long ans = 0, sumSpeed=0;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0; i<n; i++){
            pq.push(eng[i].second);
            sumSpeed += eng[i].second;
            if(pq.size()>k){
                sumSpeed -= pq.top();
                pq.pop();
            }
            //removing the min. speed from the top and including the next speed
            //and making a way for the new efficiency, which may be less
            //but we already get the ans variable storing that
            ans = max( ans, sumSpeed*eng[i].first);
        }
        
        return ans%MOD;
        
    }
};