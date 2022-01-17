/*Problem => Spiral traversal of matrix
  Problem Link => https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/
*/

vector<int> spirallyTraverse(vector<vector<int> > matrix, int m, int n) {
        vector<int>spiral;
        int m =  matrix.size();
        int n = matrix[0].size();
        
        vector<vector<bool>>seen(m, vector<bool>(n, false));
        int row = 0, col =0, dir = 0;
        int dr[4] = {0,1,0,-1};
        int dc[4] = {1,0,-1,0};
        
        int n_row, n_col;
        
        //traverse for all the elements
        for(int i=0; i<m*n; i++){
            spiral.push_back(matrix[row][col]);
            seen[row][col] = true;
            
            n_row = row + dr[dir];
            n_col = col + dc[dir];
            
            if( (n_row>=0 && n_row<m) && (n_col>=0 && n_col<n) && !seen[n_row][n_col])
            {
                row = n_row;
                col = n_col;
            }
            
            else{
                dir = (dir+1)%4;
                row += dr[dir];
                col += dc[dir];
            }
        }
        
        return spiral;
}