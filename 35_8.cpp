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
const int N=1e5+2,MOD=1e9+7;

int dp[N];

int lis(vi &a,int n){
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n]=1; //single element is also an lis

    rep(i,0,n){
        if(a[n] > a[i]){
            dp[n] = max(dp[n],1+lis(a,i));
        }
    }
    return dp[n];
}
int main()
{
    rep(i,0,N){
        dp[i]=-1;
    }
    int n;
    cin>>n;

    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }

    cout<<lis(a,n-1)<<endl;

    // tabulation
    vi dp2(n,1);
    int ans=0;
    
    rep(i,1,n){
        rep(j,0,i){
            if(a[i] > a[j]){
                dp2[i] = max(dp2[i],1+dp2[j]);
            }
        }
        ans=max(ans,dp2[i]);
    }
    cout<<ans;
 return 0;
}
// input,
// 9
// 10 22 9 33 21 50 52 60 80