/*
	problem => Tree Serialisation and Deserialisation
	Problem Link => https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1
*/

class Solution
{
	 public:
    //Function to serialize a tree and return a list containing nodes of tree.
	vector<int>arr;

	void inorder(Node* root){
		if(root!=nullptr){
			inorder(root->left);
			arr.push_back(root->data);
			inorder(root->right);
		}

		else 
			return;
	}

	vector<int> serialize(Node* root){
		inorder(root);
		return arr;
	}

    Node* deSerialize(vector<int> &A){
    	Node* root = new Node(-1);
    	Node* temp = root;
    	for(int i=0; i<A.size(); i++){
    		temp->left = new Node(A[i]);
    		temp = temp->left;
    	}

    	return root->left;
    }