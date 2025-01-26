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

const int N = 1e5+2, MOD = 1e9+7;
int dp[N];

int minNumOfsqrs(int n){
    if(n==0 || n==1 || n==2 || n==3 ){
        return n;
    }
    if(dp[n] != MOD){
        return dp[n];
    }
    for(int i=1; i*i<=n; i++){
        dp[n] = min(dp[n], 1 + minNumOfsqrs(n-i*i));
    }
    return dp[n];
}
int main()
{
    int n;cin>>n;
    //memorization
    rep(i,0,N){
        dp[i]= MOD;
    }
    cout<<minNumOfsqrs(n)<<endl;

    vi dp(n+1, MOD);
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;

    for(int i=1; i*i<=n; i++){
        for(int j=0; i*i+j <= n;j++){
            dp[i*i + j]= min(dp[i*i + j], 1+ dp[j]);
        }
    }
    cout<<dp[n]<<endl;
    
 return 0;
}