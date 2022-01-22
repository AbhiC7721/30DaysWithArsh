/*
	Problem => Connect ndoes at the same level
	Problem Link => https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1/
*/

class Solution{
	public:
		void connect(Node* root){
			queu<Node*>q;
			q.push(root);
			q.push(nullptr);

			while(!q.empty()){
				Node* p = q.front();
				q.pop();
				if(p==nullptr)
					if(!q.empty())
						q.push(nullptr);
				else{
					p->nextRight = q.front();
					  if(p->left)
						 q.push(p->left);
					   if(p->right)
						 q.push(p->right);
				}
			}
		}
}	