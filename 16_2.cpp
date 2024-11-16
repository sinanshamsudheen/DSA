#include<iostream>
using namespace std;

bool arraysort(int arr[],int n){
    if(n==1){
        return true;
    }
    bool restArray=arraysort(arr+1,n-1);
    // if(arr[0]<arr[1] && restArray){
    //     return true;
    // }
    return (arr[0]<arr[1] && restArray);
}

void dec(int n){
    if(n==1){
        cout<<"1"<<endl;
        return;
    }
    cout<<n<<endl;
    dec(n-1);
}
void inc(int n){
    if(n==1){
        cout<<"1"<<endl;
        return;
    }
    inc(n-1);
    cout<<n<<endl;
}

int firstocc(int arr[],int n,int i,int key){
    if(arr[i]==key){
        return i;
    }
    if(i==n){
        return -1;
    }
    return firstocc(arr,n,i+1,key);
}

int lastocc(int arr[],int n,int i,int key){
    if(i==n){
        return -1;
    }
    int restArray=lastocc(arr,n,i+1,key);
    if(restArray!=-1){
        return restArray;
    }
    if(arr[i]==key){
        return i;
    }
    return -1;
}
int main()
{
    // int arr[]={1,6,2,3,4,5};
    // cout<<arraysort(arr,5);
    // int n;cin>>n;
    // inc(n);
    // dec(n);

    int a[]={4,2,1,2,5,2,7};
    cout<<firstocc(a,7,0,2)<<endl;
    cout<<lastocc(a,7,0,2)<<endl;
 return 0;
}