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
    int  n=8;
    vi a = {1,11,2,10,4,5,2,1};
    vi forward(n,1),backward(n,1);
    rep(i,0,n){
        rep(j,0,i){
            if(a[i]>a[j]){
                forward[i]=max(forward[i],1+forward[j]);
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(a[i]>a[j]){
                backward[i] = max(backward[i],1+ backward[j]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans= max(ans,forward[i] + backward[i]-1);
    }
    cout<<ans;
 return 0;
}