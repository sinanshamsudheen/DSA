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
const int N=1e3+2,MOD=1e9+7;

int main()
{
    int n; cin>>n;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    int curr=0,maxTillNow=0;

    rep(i,0,n){
        curr += a[i];
        maxTillNow = max(curr,maxTillNow);

        if(curr < 0){
            curr=0;
        }

    }
    cout<<maxTillNow;
 return 0;
}
