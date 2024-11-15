// inclusion and exclusion principle

#include<iostream>
using namespace std;
 int divisible(int n,int a,int b){
    int c1=n/a;
    int c2=n/b;

    int c3=n/(a*b);
    return c1+c2-c3;
 }

// Elucide algorithm to find GCD
 int gcd(int a,int b){
    while(b!=0){
        int rem=a%b;
        a=b;
        b=rem;
    }return a;
 }
int main()
{
    // int n,a,b;
    // cin>>n>>a>>b;
    // cout<<divisible(n,a,b)<<endl;

    int c,d; cin>>c>>d;
    cout<<gcd(c,d)<<endl;
 return 0;
}
