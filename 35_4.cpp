// this solution is wrong
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
int dp[N][N];
int coinChange(int arr[],int m,int v){
    if(v==0){
        return 1;
    }
    if(v<0){
        return 0;
    }
    if(v<=0){
        return 0;
    }
    if(dp[m][v]!=-1){
        return dp[m][v];
    }
    
    dp[m][v] = coinChange(arr,m,v-arr[m-1]) + coinChange(arr,m-1,v);
    return dp[m][v];
}
int main()
{
    rep(i,0,N){
        rep(j,0,N){
            dp[i][j]=-1;
        }
    }
    int arr[]={1,2,5,10,20,50,100,200,500,2000};
    int m=10;
    int v=388;

    cout<<coinChange(arr,m,v)<<endl;
 return 0;
}