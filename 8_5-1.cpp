// This program finds the first repeating element in an array by using an 
// auxiliary array idx to keep track of the first occurrence index of each element.
#include "bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    const int N = 1e6+2;
    // (1e6 = 10 to the pow 6)
    int idx[N];
    for(int i=0;i<N;i++){
        idx[i]=-1;
    }
    int minidx = INT_MAX;

    for(int i=0;i<n;i++){
        if(idx[a[i]] != -1){
            minidx = min(minidx,idx[a[i]]);
        }
        else{
            idx[a[i]]=i;
        }
    }
    if(minidx == INT_MAX){
        cout<<"-1"<<endl;
    }
    else{
        cout<<minidx + 1<<endl;
    }
 return 0;
}  