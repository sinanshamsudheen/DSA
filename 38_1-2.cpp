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

vector<vi> multiply(vector<vi> a,vector<vi> b){
    int n = a.size();
    vector<vi> ans(n,vi(n,0));

    rep(i,0,n){
        rep(j,0,n){
            rep(k,0,n){
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ans;
}

vector<vi> matrixExponentiate(vector<vi> &a,int n){
    if(n==0){
        int sz = a.size();
        vector<vi> ans(sz, vi(sz,0));
        for(int i=0;i<sz;i++){
            ans[i][i]=1;
        }
        return ans;
    }
    if(n==1){
        return a;
    }
    vector<vi> temp= matrixExponentiate(a,n/2);
    vector<vi> ans= multiply(temp,temp);

    if(n&1){//n is odd
        ans = multiply(ans,a);
 
    }
    return ans;
}
int main()
{
    int n;cin>>n;
    vector<vi> a={{1,1},{1,0}};
    vector<vi> ans=matrixExponentiate(a,n);

    int sz = ans.size();
    for(int i=0;i<sz; i++){
        for(int j=0;j<sz;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
 return 0;
}