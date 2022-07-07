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

// RECURSION METHOD.
// bool Searches(node* root, int target){
//     if(root==NULL){
//         return false;
//     }
//     if(root->data==target){
//         return true;
//     }
//     if(root->data>target){
//         return Searches(root->left,target); 
//     }
//     else{
//         return Searches(root->right,target);
//     }
// }



// ITERATIVE METHOD
bool Searches(node* root,int target){
    node* temp = root;
    while(temp!=NULL){
        if(target==temp->data){
            return true;
        }
        else if(target>temp->data){
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
    }
    return false;
}





int main(){
    node* root = NULL;
    root = insertionBST(root);
    int target = 50;
    cout<<"Search in BST:: "<<Searches(root,target);
    return 0;
}