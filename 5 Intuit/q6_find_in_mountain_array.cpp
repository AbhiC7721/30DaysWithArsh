/*
    Problem  => Find in mountain array
    Problem Link => https://leetcode.com/problems/find-in-mountain-array
*/


/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int lo=0, hi=n-1;
        int mid, peak;
        
        //first find the peak element and then 
        //do 2 binary searches in 2 parts of the array
        
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            if(arr.get(mid)<arr.get(mid+1))
                lo = mid+1;
            else
                hi = mid;
        }
        peak = hi;
        
        
        // 2nd binary search on increasing array
        lo = 0;
        hi = peak;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(arr.get(mid)==target)
                return mid;
            else if(arr.get(mid) < target)
                lo = mid+1;
            else
                hi = mid-1;
        }
        
        //peak can never be the last element of the array
        lo = n-1;
        hi = peak;
        
        cout<<n<<'\n';
        
        while(lo<=hi){
            mid = hi + (lo-hi)/2;
            if(arr.get(mid)==target)
                return mid;
            else if(arr.get(mid) < target)
                hi = mid-1;
            else
                lo = mid+1;
        }
        
        return -1;
    
    }
};