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
    int n=5,W=11;
    vi wt={3,2,4,5,1};
    vi val={4,3,5,6,1};
    vi dp(W+1,0);
    for(int j=0;j<=W;j++){
        for(int i=0;i<n;i++){
            if(j-wt[i]>=0){ 
            dp[j]=max(dp[j],val[i] + dp[j - wt[i]]);
            }
        }
    }
    cout<<dp[W]<<endl;
 return 0;
}