 //balanced height
#include "bits/stdc++.h"
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int calcHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    int LHeight=calcHeight(root->left);
    int RHeight=calcHeight(root->right);
    return max(LHeight,RHeight)+1;
}
// bool isBalanced(Node* root){
//     if(root==NULL){
//         return true;
//     }
//     if(isBalanced(root->left==false)){
//         return false;
//     }
//     if(isBalanced(root->right==false)){
//         return false;
//     }

//     int lh=calcHeight(root->left);
//     int rh=calcHeight(root->right);
//     if(abs(lh-rh)<=1){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

bool isBalanced2(Node* root,int* height){
    if(root==NULL){
        return true;
    }
    int lh=0,rh=0;
    if(isBalanced2(root->left,&lh)==false){
        return false;
    }
    if(isBalanced2(root->right,&rh)==false){
        return false;
    }
    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }else{
        return false;
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int height=0;
    if(isBalanced2(root,&height)){
        cout<<"Balanced tree"<<endl;
    }else{
        cout<<"Unbalanced"<<endl;
    }

    return 0;
}