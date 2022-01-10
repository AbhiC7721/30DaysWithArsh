/*
	Problem => Print brackets sequence in matrix chain multiplication
*/


class Solution{
public:
	string seq;

	void bracket_print(int i, int j, int n, vector<vector<int>>& bracket, char& name){
		if(i==j){
			seq += name;
			name++;
			return;
		}

		seq += "(";

		bracket_print(i, bracket[i][j], n, bracket, name);
		bracket_print(bracket[i][j] + 1, j, bracket, name);

		seq += ")";
	}

	string matrixChainOrder(int p[], int n){
		vector<vector<int>>mat(n, vector<int>(n, 0));
		vector<vector<int>>bracket(n, vector<int>(n, 0));

		for(int len = 2; len<n; len++){

			for(int i=1; i<n-len+1; i++){

				int j = i+len-1;
				mat[i][j] = INT_MAX;
				for(int k=i; k<=j-1; k++){
					int cost = mat[i][k] + p[i-1]*p[k]*p[j] + mat[k+1][j];
					if(cost < mat[i][j]){
						mat[i][j] = cost;
						bracket[i][j] = k;
					}
				}
			}
		}
		char name = 'A';
		bracket_print(1, n-1, n, bracket, name);
		return seq;
	}

	

};