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
int calcDiameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int LHeight=calcHeight(root->left);
    int RHeight=calcHeight(root->right);
    int currDiameter = LHeight+RHeight+1;

    int LDiameter = calcDiameter(root->left);
    int RDiameter = calcDiameter(root->right);

    return max(currDiameter, max(LDiameter,RDiameter));
}
int calcDiameter2(Node* root,int* height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh=0,rh=0;
    int lDiameter = calcDiameter2(root->left,&lh);
    int rDiameter=calcDiameter2(root->right,&rh);

    int currDiameter = lh+rh+1;
    *height=max(lh,rh)+1;

    return max(currDiameter,max(lDiameter,rDiameter));
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

    cout<<calcHeight(root);
    cout<<endl;
    cout<<calcDiameter(root);
    cout<<endl;

    //optimized approach
    int height=0;
    cout<<calcDiameter2(root,&height);
    
    return 0;
}