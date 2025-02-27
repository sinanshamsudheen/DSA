#include<iostream>
#include<set>
#include<vector>
#include<climits>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstring>

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first 
#define ss second
#define setBits(x) builtin_popcount(x)
using namespace std;
const int N=1e3+2,MOD=1e9+7;

int power(int a,int n){

    a %= MOD;
    int ans = 1;
    while(n>0){
        if(n & 1){ //if lowermost position of n is 1
            ans = (ans*a)%MOD;
        }
        a = (a*a)%MOD;
        n=n>>1;
    }
    return ans;
}
int main()
{
    int a,n;
    cin>>a>>n;
    cout<<power(a,n)<<endl;
 return 0;
}