// Kadane with rapping
#include"bits/stdc++.h"
using namespace std;
int kadane(int a[],int n){

    int currsum=0;
    int maxSum= INT_MIN;
    for(int i=0;i<n;i++){
        currsum+=a[i];
        if(currsum<0){
            currsum=0;
        }
        maxSum = max(maxSum, currsum);
    }
    return maxSum;
}
int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int wrapsum;
    int nonwrapsum;

    nonwrapsum=kadane(a,n);
    int totalsum=0;
    for(int i=0;i<n;i++){
        totalsum+=a[i];
        a[i]=-a[i];
    }
    wrapsum=totalsum+kadane(a,n);
    cout<<max(wrapsum,nonwrapsum)<<endl;
 return 0;
}