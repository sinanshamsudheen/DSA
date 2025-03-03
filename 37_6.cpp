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

#define int long long
using namespace std;
const int N=1e3+2,MOD=1e9+7;


int power(int x,int y,int p){
    int res=1;
    x = x % p;
    while(x > 0){
        if(y&1){
            res = (res * x) % p;
        }
        y =y>>1;
        x = (x*x) % p;
    }
    return res;
}
int modInverse(int a,int p){
    return power(a,p-2,p);
}
int modfact(int n,int p){
    if(p <= n){
        return 0;
    }
    int res = (p-1);
    for(int i = n+1; i<p;i++){
        res = (res * modInverse(i,p))%p;
    }
    return res;
}
int32_t main()
{
    int t;cin>>t;
    while(t--){
        int n,p;cin>>n>>p;
        cout<<modfact(n,p)<<endl;
    }
    int n,p;cin>>n>>p;
    cout<<modfact(n,p)<<endl;
 return 0;
}