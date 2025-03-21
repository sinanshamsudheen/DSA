#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    
    node(int val){
        data=val;
        next=NULL;
    }
};
void insertAtTail(node* &head,int val){

        node* n = new node(val);

        if(head==NULL){
            head=n;
            return;
        }
        node * temp= head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
        
    }
// void append(node* &head,int app){
//     node* temp=head;
//     while(temp->next!=NULL){
//         temp=temp->next;
//     }
//     node* tail=temp;
//     node* newtail=tail-app;
//     node* newhead=tail-app+1;

//     do{
//         newhead=head;
//         newtail=tail;
//     }
//     while(temp->next!=NULL);
// return newhead;
// }

int length(node* head){
    int l=0;
    node* temp=head;
    
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

node* kappend(node* &head,int k){
    node* newHead;
    node* newTail;
    node* tail=head;
    int l=length(head);
    k=k%l; //for k > l
    int count=1;

    while(tail->next!=NULL){
        if(count==l-k){
            newTail=tail;
        }
        if(count==l-k+1){
            newHead=tail; 
               }       
    tail=tail->next;
    count++;
    }

    newTail->next=NULL;
    tail->next=head;
 return newHead;
}
void display(node* head){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }cout<<"null"<<endl;
    }
int main()
{
    node* head=NULL;
    // insertAtTail(head,1);
    // insertAtTail(head,2);
    // insertAtTail(head,3);
    // insertAtTail(head,4);
    // insertAtTail(head,5);

    int arr[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++){
        insertAtTail(head,arr[i]);
    }
    display(head);
    node* newhead=kappend(head,3);
    display(newhead);
 return 0;
}