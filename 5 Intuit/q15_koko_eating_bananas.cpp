/*
    Problem => Koko Eating bananas
    Problem Link => https://leetcode.com/problems/koko-eating-bananas/
*/

class Solution {
public:
    
    int check(vector<int>&piles, int mid, int h){
        int totalHrs = 0;
        for(int i=0; i<piles.size(); i++){
            totalHrs += piles[i]/mid;
            if(piles[i]%mid !=0)
                totalHrs++;
        }
        return totalHrs;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int lo = 1;
        int hi = 1000000004;
        int mid, totalHrs;
        
        while(lo<hi){
            mid =  (lo+hi)/2;
        totalHrs = check(piles, mid, h);
        if(totalHrs <= h){
            hi = mid;
        }
        else
            lo = mid+1;
        }
        return hi;
    }
};