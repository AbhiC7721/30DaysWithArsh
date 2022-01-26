/*
	Problem => Number of Boomerangs
	Problem Link => https://leetcode.com/problems/number-of-boomerangs/
*/

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;
        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j)
                    continue;
                // int dist = euclideanDist(points[i], points[j]);
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int dist = dx*dx + dy*dy;
                mp[dist]++;
            }
            
            for(auto it: mp){
                if(it.second>0){
                   int num = it.second;
                    count += num*(num-1); 
                 }
            } 
            
            mp.clear();
           
        }
        
        return count;
    }
    
    // int euclideanDist(vector<int>p1, vector<int>p2){
    //    int dx = p1[0] - p2[0];
    //    int dy = p1[1] - p2[1];
    //    return dx*dx + dy*dy;
    // }
};
