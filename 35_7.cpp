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

const int N = 1e3+2,MOD=1e9+7;
int wt[N],val[N];

int dp[N][N];

int knapsack(int n,int w){
    if(w<=0){
        return 0;
    }
    if(n<=0){
        return 0;
    }
    if(dp[n][w] != -1){
        return dp[n][w];
    }
    if(wt[n-1] > w){
        dp[n][w]= knapsack(n-1,w);
    }
    else{
        dp[n][w] = max(knapsack(n-1,w), knapsack(n-1,w-wt[n-1])+val[n-1]);
        }
    return dp[n][w];
}
int main()
{
    int n;cin>>n;
    //memoization
    rep(i,0,N){
        rep(j,0,N){
            dp[i][j]=-1;
        }
    }
    
    rep(i,0,n){
        cin>>wt[i];
    }
    rep(i,0,n){
        cin>>val[i];
    }

    int w;cin>>w;

    cout<<knapsack(n,w)<<endl;
 return 0;
}