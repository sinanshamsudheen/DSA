// pointers 
#include<iostream>
using namespace std;
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main()

{
    // int a=10;
    // int *aptr;
    // aptr=&a;

    // cout<<&a<<endl;
    // cout<<aptr<<endl;
    // cout<<*aptr<<endl;

    // pointer to array
//  int arr[]={10,20,30};
//  int *ptr=arr;
//  for(int i=0;i<3;i++){
//     cout<<*(arr+i)<<endl;
//     ptr++;
//  }

//  pointer to pointer

// int a=10;
// int *p=&a;
// int **q=&p;

// cout<<*q<<endl;
// cout<<**q<<endl;

// pointers in functions

int a=4,b=2;

        // int *aptr=&a;
        // int *bptr=&b;

        // swap(*aptr,*bptr);
swap(&a,&b);
cout<<a<<" "<<b<<endl;
 return 0;
}