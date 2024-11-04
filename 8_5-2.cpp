// Q- given an unsorted array A of size N of non-negative integers,
//  find a continuos subarray which adds to a given number S.

//  contraints,
//   1 <= N <= 1e5
//   0 <= Ai <= 1e10

// intput,
// 5 12
// 1 2 3 7 5
// output= 2 4

#include "bits/stdc++.h"
using namespace std;
int main(){
    int n,s;
    cin>>n>>s;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int i=0,j=0,st=-1,en=-1,sum=0;

    while(j<n && sum+a[j]<= s){
        sum += a[j];
        j++;
    }
    if (sum == s){
        cout<< i+1<<" "<<j<<endl;
        return 0;
    }
    while(j<n){
        sum += a[j];
        while(sum>s){
            sum -= a[i];
            i++; 
        }
        
    if(sum == s){
        st = i+1;
        en = j+1;
        break;
    }
    j++;
    }
    cout<< st <<" "<< en <<endl; 
return 0;
}