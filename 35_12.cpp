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
vi a;
int dp[N][N];
int solve(int i,int j){
    if(i==j){
        return a[i];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(i>j){
        return 0;
    }
    int l=a[i]+min(solve(i+2,j),solve(i+1,j-1));
    int r=a[j] + min(solve(i,j-2),solve(i+1,j-1));

     dp[i][j]=max(l,r);
     return dp[i][j];
}
int main()
{
    rep(i,0,N){
        rep(j,0,N){
        dp[i][j]=-1;
        }
    }
    int n;cin>>n;
    a=vi(n);
    for(auto &i:a){
        cin>>i;
    }
    cout<<solve(0,n-1);
 return 0;
}