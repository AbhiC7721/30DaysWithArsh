/*
 Problem => Delete n nodes after m nodes of a linked list
 Problem Link => https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1/
*/

class Solution {
  public:
  	void linkdelete(struct Node  *head, int M, int N){
  		Node* temp1 = head;
  		while(temp1!=nullptr){
  			for(int i=0; i<M-1 && temp1!= nullptr; i++)
  				temp1 = temp1->next;
  			Node* temp2 = temp1->next;
  			for(int i=0; i<N && temp2!=nullptr; i++)
  				temp2 = temp1->next;
  			temp1->next = temp2;
  			temp1 = temp2;
  		}
  	} 

};

//o(m+n) as we just need to implement the said question