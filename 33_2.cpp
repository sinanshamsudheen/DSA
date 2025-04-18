// indian coin change problem
#include<iostream>
#include<set>
#include<vector>
#include<climits>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
 
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
    int n;
    cin>>n;

    vi a(n);

    rep(i,0,n){
        cin>>a[i];
    }

    int x;
    cin>>x;

    sort(a.begin(),a.end(),greater<int>());
    int ans=0;

    for(int i=0;i<n;i++){
        ans += x/a[i];
        x-= x/a[i]*a[i];
    }
    cout<<ans<<endl;
 return 0;
}