#include <bits/stdc++.h>
using namespace std;

template <typename T>class Node{
	private:
		 int data;
		 Node *left;
		 Node *right;
		 int height;
		 
	public:
		
	  int get_height(Node<T> *n){
	  	if(n==NULL){
	  		return 0;
		  }
		else{
			return n->height;
		}  
	  }
	  
	  int getBalance(Node<T> *n){
	  	int balance;
	  	balance=(n->left)-(n->right);
	  	return balance;
	  }
	  	
	  Node *createnode(Node<T> *newnode,T key){
	  	newnode->data=key;
	  	newnode->left=NULL;
	  	newnode->right=NULL;
	  	height=1;
	  }	
	  
	  
	  Node *insertnode(Node<T> *n,T key){
	  	 if(n==NULL){
             createnode(n,key);
		   }
		   
		 else{
		 	if(n->data<key){
		 		createnode(n->left,key);
			 }
			else{
				createnode(n->right,key);
			}
		} 
		 
		n->height=1+max(get_height(n->left),get_height(n->right)); 
		int balance_factor=getBalance(n);
		if (balance_factor>1 && key < (n->left->data)){//left-left imbalnce
			return rightrotate(n);
		}
		if(balance_factor<-1 && key< n->right->data){ //right-right imbalnce
			return leftrotate(n);
		}
        if(balance_factor>1 && key< n->right->data){ //left right imbalance
        	n->left=leftrotate(n);
        	return rightrotate(n->left);
		}
		if(balance_factor<-1 && key> n->right->data){ //right left imbalance
			n->right=rightrotate(n);
			return leftrotate(n->right);
		}
	 }
	  
	 //Rotations in avl tree
	 Node *rightrotate(Node<T> *y){ //for left-left imbalnce
	 	Node<T> *x=y->left;
	 	Node<T> *T2=x->right; //NULL VALUE
	 	
	 	//performing rotation
	 	x->right=y;
	 	y->left=T2;
	 	return x;
	 } 
	 
	 Node *leftrotate(Node<T> *x){ //for right-right imbalnce
	 	 Node<T> *y=x->right;
	 	 Node<T> *T2=y->left;
	 	 
	 	 //performing rotation
	 	 y->left=x;
	 	 x->right=T2;
	 	 return y;
	 }
	 
	 Node *preorder(Node<T> *x){
	 	cout<<x->data<<"\n";
	 	preorder(x->left);
	 	preorder(x->right);
	 }
	 
	 Node *inorder(Node<T> *x){
	 	inorder(x->left);
	 	x->data;
	 	inorder(x->right);
	}
	
	Node *postorder(Node<T> *y){
		postorder(y->left);
		cout<<y->data;
		postorder(y->right);
	}
	
	Node *minValueNode(Node<T> *node){
		Node<T> *current=node;
		while(current->left!=NULL){
			current=current->left;
		}
		return current;
	}
	Node *deletenode(Node<T> *r,int v){
		Node<T> *temp;
		if(r==NULL){
			return r;
		}
		else if(v<r->data){ //if value is smaller then go to left sub tree
			deletenode(r->left,v);
		}
		else if(v>r->data){ //if value is greater then go to right sub tree
			deletenode(r->right,v);
		}
		else{// if value matches
			if(r->left==NULL){ //with only right child or no child
				temp=r->right;
				delete r;
				return temp;
			}
			
			else if(r->right==NULL){ //node with only left child
			temp=r->left;
			delete r;
			return temp;
		}
		else{ //node with two children
			temp=minValueNode(r->right);
			r->data=temp->data;
			r->right=deletenode(r->right,temp->data);
		}
		
		//balancing the tree
		r->height=1+max(get_height(r->left),get_height(r->right));
		int bf=getBalance(r);
		if (bf>1 && getBalance(r->left)>=0){
			return rightrotate(r);
		}
		else if(bf<-1 && getBalance(r->right)<=0){
			return leftrotate(r);
		}
		else if(bf>1 && getBalance(r->left)==-1){
			r->left=leftrotate(r->left);
			return rightrotate(r);
		}
		else if(bf<1 && getBalance(r->right)==1){
			r->right=rightrotate(r->left);
			return leftrotate(r);
		} 
	  return r;	
	}
    }
    
    bool search(Node<T> *r,T value){
    	while(r!=NULL){
		
    	if(r->data==value){
    		return true;
		}
		else if(value<r->data){
			search(r->left,value);
		}
		else if(value>r->data){
			search(r->right,value);
		}
		
	}
	 return false;
   }
   
   void printTree(Node *root,string indent,bool last){
   	  if(root!=nullptr){
   	  	     cout<<indent;
   	  	     if(last){
   	  	     	 cout<<"R----";
   	  	     	 indent+="  ";
			}
			else{
				cout<< "L----";
				indent+="|  ";
			}
   	       cout<<root->data<<endl;
   	       printTree(root->left, indent, false);
           printTree(root->right, indent, true);
	}
	  
   }
};

int main(){
	/*Node<int> *root=NULL;
	root=root->insertnode(root,5);
	root=root->deletenode(root,5);
	bool t=root->search(root,5);
	root->printTree(root," ",true);*/
	
	int pc=1;
	while(pc==1){
		cout<<"1-insert\n";
		cout<<"2-search\n";
		cout<<"3-delete\n";
		cout<<"4-preorder\n";
		cout<<"5-postorder\n";
		cout<<"6-inorder\n";
		cout<<"7-printTree\n";
		
		int ch;
		cout<<"enter the choice from above\n";
		cin>>ch;
		Node<int> *root=NULL;
		if (ch==1){
			int a;
			cout<<"enter the element to be inserted\n";
			cin>>a;
			root=root->insertnode(root,a);
		}
		
		else if(ch==2){
			
			int a;
			cout<<"enter the element to be searched\n";
			cin>>a;
			bool t=root->search(root,a);
			cout<<t;
		}
		
		if(ch==3){
			int a;
			root=root->deletenode(root,a);
			cout<<"The element"<<a<<"is deleted\n"<<endl;
		}
		if(ch==4){
		    root->preorder(root);
		}
		if(ch==5){
		    root->postorder(root);
		    cout<<endl;
		}
		if(ch==6){
		    root->inorder(root);
		    cout<<endl;
		}
		if(ch==7){
			root->printTree(root,"",true);
			cout<<endl;
		}
		cout<<"do you want to enter more(1/0)\n";
		cin>>pc;
	}
	
	return 0;
}