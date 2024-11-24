#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }

};
    void insertAtHead(node* &head,int val){
        node* n=new node(val);
        n->next=head;
        head=n;
    }

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
    void display(node* head){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }cout<<"null"<<endl;
    }

    bool search(node* head,int key){
        node* temp=head;
        while(temp!=NULL){
            if(temp->data==key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

    void deleteAthead(node* &head){
        node* todelete=head;
        head=head->next;
        delete todelete;
    }
    void deletion(node* &head,int val){

        if(head==NULL){
            return;
        }
        if(head->next=NULL){
            deleteAthead(head);
        }

        node* temp=head;
        while(temp->next->data!=val){
            temp=temp->next;
        }
        node* todelete=temp->next;
        temp->next=temp->next->next;
        delete todelete;
    }

   node* reverse(node* head){ //iterative way
    node* currptr=head;
    node* prevptr=NULL;
    node* nextptr;

    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
   } 


    node* reverseRecursive(node* &head){

        if(head==NULL || head->next==NULL){
            return head;
        }
        node* newhead= reverseRecursive(head->next);
        head->next->next=head;
        head->next=NULL;

        return newhead;
    }

    node* reversek(node* &head,int k){
        node* currptr=head;
    node* prevptr=NULL;
    node* nextptr;
int count=0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next=reversek(nextptr,k);
    }
    return prevptr;
    }

void makeCycle(node* &head,int pos){
    node* temp=head;
    node* startNode;
    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startNode;
}
bool detectCycle(node *&head){

    node* slow=head;
    node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow){
            return true;
        }
    }
}

void removeCycle(node* &head){
    node* slow=head;
    node* fast=head;

    do{
        slow=slow->next;
        fast=fast->next->next;
    }
    while(slow!=fast);

    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}
int main()
{
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    // display(head);
    // insertAtHead(head,4);
    // display(head);

    // cout<<search(head,3)<<endl;

    // deletion(head,3);
    // display(head);
    // deleteAthead(head);
    display(head);
    node* newhead=reversek(head,2);
    display(newhead);

    cout<<detectCycle(head)<<endl;
    removeCycle(head);
    cout<<detectCycle(head)<<endl;
    display(head);
     

 return 0;
}