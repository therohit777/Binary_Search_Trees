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

void Minx_value(node* root){
    node* temp = root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    cout<<temp->data;
}

void Maxe_value(node* root){
    node* temp = root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    cout<<temp->data;
}


int main(){
    node* root = NULL;
    root = insertionBST(root);
    Minx_value(root); 
    Maxe_value(root); 
    return 0;
}