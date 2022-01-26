/*
    Problem => Capacity to ship within d days
    Problem Link => https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
*/

class Solution {
public:
    
    int check(vector<int>&weights, int cap){
        int days = 0;
        int sum = 0;
        if(cap < *max_element(weights.begin(), weights.end()))
            return INT_MAX;
        for(int i=0; i<weights.size(); i++){
            sum += weights[i];
            if(sum>cap){
                sum = weights[i];
                days++;
            }
        }
        
        if(sum>0)
            days++;
        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int lo = 1, hi = 25000006;
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            int d = check(weights, mid);
            
            if(d<=days)
                hi = mid;
            else
                lo = mid+1;
        }
        
        return hi;
        
    }
};