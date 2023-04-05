#include <bits\stdc++.h>
using namespace std;
template<typename T>
class Node{
	private:
		int data;
		node *left;
		node *right;
		int height;
		
	public:
		int ret_height(Node *n){
			if(n==NULL){
				return 0;
			}
			else{
			   int h1=n->height;
			}
		}
		
	   Node* create_node(T key){
	   	  Node* n1;
	   	  n1->data=Key;
	   	  n1->left=NULL;
	   	  n1->right=NULL;
	   	  return n1;
	   }
	   
	   Node* insert_node(Node *n,T key){
	   	//n is the value of data that is at the left side of the pointer n
	   	if(n->data==NULL){
	   		n->data=Key;
	   		n->left=NULL;
	   		n->right=NULL;
	   		return n;         
		   }
		   
	   else{
	   	  if(n->data>key){
	   	  	  insert_node(n->right,T key);
			 }
			 
		if(n->data<key){
	   	  	  insert_node(n->left,T key);
			}
			
		if(n->data=key){
	   	  	  continue;
			}	 
			 
	   }	
	   
};
