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

vector<vi> MatrixMultiply(vector<vi> a,vector<vi> b){
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
int main()
{
    

 return 0;
}