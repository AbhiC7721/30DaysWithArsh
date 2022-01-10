/* Longest Mountain Problem - geeksforgeeks problem 
	Link - https://leetcode.com/problems/longest-mountain-in-array/
*/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int start = 0;
        int n = arr.size();
        int ans = 0;
        int i = 1, increase=0, decrease=0;
        while(i<n){
            increase=0, decrease=0;
            while(i<n && arr[i-1]<arr[i]){
                i++;
                increase++;
            }    
            while(i<n && arr[i-1]>arr[i]){
                i++;
                decrease++;
            }
            
            while(i< n && arr[i-1]==arr[i])
                i++;
            if(increase>0 && decrease >0)
                ans = max(ans, increase+decrease+1);
        }
        
        return ans;
    }
};

// Time complexity => O(n) and space complexity => O(1)