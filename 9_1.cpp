// two dimensional array
#include<iostream>
#include "bits/stdc++.h"
using namespace std;
int main()
{   int n,m;

    int a[n][m];
    cout<<"enter n value"<<endl;
    cin>>n;
    cout<<"enter m value"<<endl;
    cin>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    cout<<"Matrix is: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    int x;
    cin>>x;
    bool flag=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==x){
                cout<<i<<" "<<j;
                flag=true;
            // }
            // else{
            //     cout<<" Element is not found"<<endl;
            // }
        }
        }
        }
    if(flag){
                cout<<" Element is found"<<endl;
    }else{
        cout<<"Element is not found"<<endl;
    }

 return 0;
}
