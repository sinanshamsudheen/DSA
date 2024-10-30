// searching in arrays->Linear search
#include<iostream>
using namespace std;

int LinearSearch(int arr[],int key,int n){
    for(int i=0;i<=n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
int main()
{
    int n;
    cout<<"enter value of n"<<endl;
    cin>>n;

    int arr[n];
    for(int i=0;i<=n;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"enter key value"<<endl;
    cin>>key;
    cout<<LinearSearch(arr,key,n)<<endl;
 return 0;
} 