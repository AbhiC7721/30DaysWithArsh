/*
	Problem => Find all subtrees with given sum
	Problem Link => https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum
*/

class Solution {
	int ans;

	int solve(Node* root, int X){
		if(root==nullptr)
         return 0;
        int l = solve(root->left, X);
    	int r = solve(root->right, X);

    	if(X == root->data+l+r)
        	ans++;
        return root->data + l +r;
	}

	int countSubtreesWithSumX(Node* root, int X)
	{
		ans = 0;
	    int sumCal = solve(root, X);
	    return ans;
	}

};