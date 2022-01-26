/*	
	Problem => Min. swaps to arrange a binary grid
	Problem Link => https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
*/

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>trailing(n, 0);
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=n-1; j>=0; j--){
                if(grid[i][j]==1)
                    break;
                else
                    trailing[i]++;
            }
        }
        
        for(int i=0; i<n; i++){
            int j = i;
            int finalZeros = n-i-1;
            
            while(j<n && trailing[j]<finalZeros)
                j++;
            if(j==n) return -1;
            
            ans += j-i;
            
            while(j>i){
                trailing[j] = trailing[j-1];
                j--;
            }
        }
        
        return ans;
    }
};