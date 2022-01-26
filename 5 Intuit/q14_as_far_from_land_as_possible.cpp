/*
    Problem => As far from land as possible
    Problem Link => https://leetcode.com/problems/as-far-from-land-as-possible/ 
*/

int maxDistance(vector<vector<int>>& grid) {
	
        queue<pair<int, int> > q;
        int m = grid.size(), n = grid[0].size();
		for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        vector<vector<int> > DIR = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
		while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            int v = grid[x][y]; 
            for (auto &d : DIR) {
                int nx = x + d[0];
                int ny = y + d[1];
                
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] == 1) {
                    continue;n
                }
				
                if (grid[nx][ny] != 0 && grid[nx][ny] <= (v + 1)) {
                    continue;
                }
                
                grid[nx][ny] = v + 1;
                q.push({nx, ny});  
        }
        
        int mx = -1; 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 1) { 
                    mx = max(mx, grid[i][j] - 1);
                }
                
            }
        }
        return mx;
        
    }