#include<iostream>
#include<climits>
using namespace std;

struct Node{
    int data;
    Node* left,*right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

struct Information{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};
Information largestBSTinBT(Node* root){
    //base cases
    if(root==NULL){
        return {0,INT_MIN,INT_MAX,0,true};
    }
    if(root->left ==NULL && root->right==NULL){
        return {1,root->data,root->data,1,true};
    }
    //main syntax
    Information leftInfo =largestBSTinBT(root->left);
    Information RightInfo =largestBSTinBT(root->right);

    Information curr;
    curr.size = (1 + leftInfo.size + RightInfo.size);

    if(leftInfo.isBST && RightInfo.isBST && leftInfo.max < root->data && RightInfo.min > root->data){
        curr.min=min(leftInfo.min,min(RightInfo.min,root->data));
        curr.max=max(RightInfo.max,max(leftInfo.max,root->data));

        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }
    curr.ans=max(leftInfo.ans,RightInfo.ans);
    curr.isBST=false;
    return curr;
}


int main()
{
    Node* root=new Node(15);
    root->left=new Node(20);
    root->right =new Node(30);
    root->left->left= new Node(5);

    cout<<"Largest BST in BT : "<<largestBSTinBT(root).ans<<endl;
 return 0;
}