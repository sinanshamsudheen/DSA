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

const int N = 1e5+2;
int dp[N];
int fib(int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 0;
        }
        if(n==2){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = fib(n-1) + fib(n-2);
        return dp[n];
}
int main()
{
    int n;cin>>n;

    rep(i,0,N){ //memorization
        dp[i]=-1;
    }
    cout<<fib(n)<<endl;

    //tabulation
    vi dp(n+1);
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;

    for(int i =3;i<=n;i++){
        dp[i]=dp[i-1] + dp[i-2];
    }
    cout<<dp[n]<<endl;

    
 return 0;
}