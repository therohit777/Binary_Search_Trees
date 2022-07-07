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


int main(){
    node* root = NULL;
    root = insertionBST(root);
    Level_Order_Traversal(root);
    return 0;
}