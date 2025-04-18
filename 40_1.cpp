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

int a[N],tree[4*N];

void build(int node,int st,int end){
    if(st==end){
        tree[node] = a[st];
        return;
     }
     int mid=(st+end)/2;
     build(2*node,st,mid);
     build(2*node+1,mid+1,end);

     tree[node]=tree[2*node] + tree[2*node+1];
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    build(1,0,n-1);
    for(int i=1;i<15;i++){
        cout<<tree[i]<<endl;
    }
 return 0;
}