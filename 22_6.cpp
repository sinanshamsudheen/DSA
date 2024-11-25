// doubly linked list

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAthead(node* &head,int val){
     node* n=new node(val);

     n->next=head;
     if(head!=NULL){
     head->prev=n;
     }
     head=n;
}
void insertAttail(node* &head,int val){

    if(head==NULL){
        insertAthead(head,val);
    }
    node* n=new node(val);
    node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->"<<" ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void deleteAthead(node* &head){
    node* todelete=head;

    head=head->next;
    head->prev=NULL;

    delete todelete;
}
  void deletion1(node* &head,int val){
    if(val==1){
        deleteAthead(head);
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
       todelete->prev->next=todelete->next;
       todelete->next->prev=todelete->prev;
    delete todelete;
  }
void deletion2(node* head,int pos){
    if(pos==1){
        deleteAthead(head);
    }
    node* temp=head;
    int count=1;
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;

    delete temp;
}
int main()
{
    node* head=NULL;
    insertAttail(head,1);
    insertAttail(head,2);
    insertAttail(head,3);
    insertAttail(head,4);
    insertAttail(head,5);

    display(head);
    deleteAthead(head);
    display(head);
 return 0;
}