#include <iostream>
using namespace std;
struct node{
   int data;
   int height;
   struct node * left;
   struct node * right;
   node(int key){
    data=key;
    height=0;
    left=NULL;
    right=NULL;
   }

};

typedef struct node node;

int get_height(node *n){
    if(n==NULL){
        return 0;
    }

   else{
     return n->height;
   }

}

class Avltree{
   public:
     node * root;
     node * insert(node *root,int key){
        if(root==NULL){
            return new node(key); 
        }
        if(root->data>key){
            root->left= insert(root->left,key);
        }
        if(root->data<key){
            root->right=insert(root->right,key);
        }

        int balance;
        balance=get_height(root->left)-get_height(root->right);
        if(balance>1 || balance<-1){
            if(balance>1){
                if(root->left->left!=NULL){
                    root=rightrotate(root->left->left);
                }
                else{
                    root->left=leftrotate(root->left);
                    root=rightrotate(root); 
                }
            }

            if(balance<-1){
                if(root->right->right!=NULL){
                    root=leftrotate(root->right->right);
                }
                else{
                    root->right=rightrotate(root->rotate);
                    root=leftrotate(root);
                }
            }
        }
        return root;
     }

    node * leftnode(node * n){
        node* temp=n->left;
        node* temp2=temp->right;

        temp->right=n->data;
        node* temp3=temp->right;

        temp3->left=temp2;
        
    }

     void inorder(node *root){
        if(root==NULL){ 
            return ;
        }
        inorder(root->left);
        cout<<root->data<<endl;
        inorder(root->right);
     }

     
};


int main(){
    Avltree v;
    v.root=NULL;

    v.root=v.insert(v.root,5);
    v.root=v.insert(v.root,50);
    v.root=v.insert(v.root,25);
    v.root=v.insert(v.root,57);

    v.inorder(v.root);
    return 0;
}




































