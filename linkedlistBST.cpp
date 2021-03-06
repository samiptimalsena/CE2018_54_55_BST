#include"linkedlistBST.h"
#include<iostream>

using namespace std;

node::node(){
    data=0;
    left=right=NULL;
}

node::node(int value){
    data=value;
    left=right=NULL;
}

node::~node(){}


LinkedBST::LinkedBST(){
}

LinkedBST::~LinkedBST(){}

void LinkedBST::add(int data){
}



bool LinkedBST::search(int data){}


void LinkedBST::add(node *root,int data){
if (root->data==0){
    root->data=data;
}else{
        if (data < root->data){
            if (!root->left){ 
                node *newnode=new node(data); 
                root->left=newnode;
            }
            else{
                add(root->left,data);
            }
        }
        else if (data > root->data){
            if (!root->right){ 
                node *newnode=new node(data); 
                root->right=newnode;
            }
            else{
                add(root->right,data);
            }
        }
    }
}

bool LinkedBST::search(node *root,int targetKey){
    if(root->data==0){
        cout<<"It is an empty tree"<<endl;
    }
    else{
        node *p=new node();
        p=root;
        while(p){
            if(targetKey>p->data){
                p=p->right;
            }
            else if(targetKey<p->data){
                p=p->left;
            }
            else if(targetKey==p->data){
                cout<<targetKey<<" is in the tree"<<endl;
                return 1;
                
            }
            else{
                cout<<targetKey<<" is not in the tree"<<endl;
                return 0;
            }
        }
    }
    cout<<targetKey<<" is not in the tree"<<endl;
    return 0;
}


void LinkedBST::preorderTraversal(node* root) { 
    if (!root) 
    return; 
  
    
    cout << root->data << "\t"; 
  
    
    preorderTraversal(root->left);  
  
    
    preorderTraversal(root->right); 
}

void LinkedBST::preOrderTraversal(int index){
}

 void LinkedBST:: inOrderTraversal(int index){
 	
 }

void LinkedBST::inorderTraversal(node* root){
	if(!root)
	return;
	
	inorderTraversal(root->left);
	
	cout<<root->data<<"\t";
	
	inorderTraversal(root->right);
	
}  

void LinkedBST::deleteKey(int key){
	
}

void LinkedBST:: deleteKey(node *root,int key){
	if(!root){
		return;
	}
	if(key<root->data){
		deleteKey(root->left,key);
	}
	else if(key>root->data){
		deleteKey(root->right,key);
	}
	else if(key==root->data){
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		else if(root->right==NULL){
			node *temp=new node();
			temp=root;
			delete root;
			root=temp->left;
		}
		else if(root->left==NULL){
			node *temp=new node();
			temp=root;
			delete root;
			root=temp->right;	
		}
		else{
			node *nodeToDelete=new node();
			nodeToDelete=root;
			int largest;
			largest=max(root);
			nodeToDelete->data=largest;
			deleteKey(nodeToDelete->left,largest);
			
		}
	}

}

int LinkedBST:: min(){
	
}

void LinkedBST::min(node* root){
	if(!root->left){
		cout<<"The smallest number is"<<root->data<<endl;
	}
	else{
		min(root->left);
	}
}

int LinkedBST:: max(){
	
}
int LinkedBST:: max(node* root){
	if(!root->right){
		return root->data;
	}
	else{
		 max(root->right);
	}
	
}


int main(){
	LinkedBST s;

	s.add(&s.root,46);
	s.add(&s.root,19);
	s.add(&s.root,77);
	s.add(&s.root,33);
	s.add(&s.root,81);
	s.add(&s.root,51);
	cout<<"Preorder Traversal of the tree is"<<endl;
	s.preorderTraversal(&s.root);
	cout<<endl;
	cout<<endl;
	cout<<"Inorder Traversal of the tree is"<<endl;
	s.inorderTraversal(&s.root);
	cout<<endl;
	cout<<endl;
	
	s.min(&s.root);
	int largest=s.max(&s.root);
	cout<<"The largest is"<<largest<<endl;
	
	
	
	s.preorderTraversal(&s.root);
	
	int number;
	cout<<"Enter a number you want to search  in the tree"<<endl;
	cin>>number;
	s.search(&s.root,number);
	s.deleteKey(&s.root,19);
	cout<<"Enter a number you want to search  in the tree"<<endl;
	cin>>number;
	s.search(&s.root,number);
	
}
