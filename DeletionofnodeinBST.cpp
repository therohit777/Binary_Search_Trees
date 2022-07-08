#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
     int data;
     node* left;
     node* right;
     node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
     }
};

node* insertnodes(node* root, int d){
    if(root==NULL){
        root = new node(d);
        return root;
    }
    if(d<root->data){
        root->left = insertnodes(root->left,d);
    }
    else{
        root->right = insertnodes(root->right,d);
    }

    return root;

}

node* insertionBST(node* root){
    int d;
    cout<<"Enter the data:"; 
    cin>>d;

    while(d!=-1){
        root = insertnodes(root,d);
        cin>>d; 
    }
    return root;
}

void Level_Order_Traversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        node *temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}

node* Minx_value(node* root){
    node* temp = root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

void Maxe_value(node* root){
    node* temp = root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    cout<<temp->data;
}


node* deletenodesinBST(node* root, int target){
    if(root==NULL){
        return NULL;
    }

    if(root->data==target){
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        if(root->left!=NULL && root->right==NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
         if(root->left!=NULL && root->right!=NULL){
            int minx = Minx_value(root->right)->data;
            root->data=minx;
            root->right= deletenodesinBST(root->right,minx); 
            return root;
        }
    }
    else if(root->data>target){
        root->left = deletenodesinBST(root->left,target);
        return root;
    }
    else{
        root->right = deletenodesinBST(root->right,target);
        return root;
    }

}


int main(){
    node* root = NULL;
    root = insertionBST(root);
    Level_Order_Traversal(root);
    deletenodesinBST(root,30);
    Level_Order_Traversal(root);
    return 0;
}