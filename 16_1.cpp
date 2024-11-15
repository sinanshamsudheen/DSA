// recursion- function calls itself again and again
#include<iostream>
using namespace std;

int Sum(int n){
    if(n==0){
        return 0;
    }
    int prevSum=Sum(n-1);
    return n+prevSum;
}
int power(int n,int p){
    if(p==0){
        return 1;
    }
    int prevpower=power(n,p-1);
    return n*prevpower;
}
int nfac(int n){
    if(n==0){
        return 1;
    }
    int prevnfac=nfac(n-1);
    return n*prevnfac;
}
int fibonacci(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int newfib=fibonacci(n-1)+fibonacci(n-2);
    return newfib;
}
int main()
{
    // int n; cin>>n;
    // cout<<Sum(n)<<endl;

    // int m,p; cin>>m>>p;
    // cout<<power(m,p)<<endl;
    int l; cin>>l;
    // cout<<nfac(l)<<endl;
    cout<<fibonacci(l);
 return 0;
}