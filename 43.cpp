#include<bits/stdc++.h>

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first 
#define ss second
#define setBits(x) builtin_popcount(x)
using namespace std;
const int N=1e3+2,MOD=1e9+7;

int main()
{
    int lo = 1, hi=1000000;
    int ans=-1;
    while(lo<=hi)
{   
    int mid=(lo+hi)/2;
     cout<<mid<<endl;
    cout<<flush;
    string s;cin>>s;
    if(s=="<"){
        hi = mid-1;
    }
    else{
        ans=max(ans,mid);
        lo = mid + 1;
    }
}
cout<<" ! "<<ans<<endl;
cout<<flush;
 return 0;
}