#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<climits>
 
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first 
#define ss second
#define setBits(x) builtin_popcount(x)
using namespace std;
 
int main()
{
    int n,k;
    cin>>n>>k;

    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    int s=0,ans=INT_MAX;
    rep(i,0,k){
        s += a[i];
    }
    cout<<s<<" ";
    ans=min(ans,s);

    //Sliding window
    rep(i,1,n-k+1){
        s -= a[i-1];
        s += a[i+k-1];
        ans=min(ans,s);
        cout<<s<<" ";
    }
    cout<<endl;
    cout<<ans<<endl;
 return 0;
}