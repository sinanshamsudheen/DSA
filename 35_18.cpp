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
    int n=10;
    int c2(0),c3(0),c5(0);
    vi dp(n+1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=min({2*dp[c2],3*dp[c3],5*dp[c5]});
        if(2*dp[c2]==dp[i]){
            c2++;
        }
        if(3*dp[c3]==dp[i]){
            c3++;
        }
        if(5* dp[c5]==dp[i]){
            c5++;
        }
    }
    cout<<dp[n-1]<<endl;

 return 0;
}
// dp approach,
// keep 3 pointers, think of it as merging three sorted lists.
// assume you have Uk,the k'th ugly number, then U(k+1) must be Min(p1*2,p2*3,p3*5).
// where p1,p2,p3 will be already generated numbers.