/*
 Tree Burning Problem => Minimum time taken to burn tree from a particular node
*/

class Solution {
  public:

  	int ans = 0;
  	pair<int, bool>dfs(Node*root, int target){
        if(root==nullptr)
        	return {0, false};
        if(root->data==target){
            ans =  max(dfs(root->left, target).first, dfs(root->right, target).first);
        	return {1, true};
        }


        pair<int, bool> left = dfs(root->left, target);
        pair<int, bool> right = dfs(root->right, target); 

        if(left.second==true){
            ans = max(ans, right.first + left.first);
            return {left.first+1, true};
        }  

        else if(right.second){
            ans = max(ans, right.first + left.first);
            return {right.first+1, true};
        } else {
        	return {max(left.first, right.first)+1, false};
        }
    }

    int minTime(Node* root, int target) 
    {
    	dfs(root, target);
        return ans;
    }