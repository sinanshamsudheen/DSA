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
int a[N];
int dp[N][N];

int mcm(int i,int j){
    if(i==j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    dp[i][j]=MOD;
    for(int k=i;k<j;k++){
        dp[i][j]=min(dp[i][j],mcm(i,k) + mcm(k+1,j)+ a[i-1]*a[k]*a[j]);
    }
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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<mcm(1,n-1)<<endl;
 return 0;
}