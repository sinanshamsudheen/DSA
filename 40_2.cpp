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
int query(int node,int st,int end,int l,int r){
    if(st > r || end < l){
        return 0;
    }
    if(l<= st && end<= r){
        return tree[node];
    }
    int mid=(st+end)/2;

    int q1 = query(2*node,st,mid,l,r);
    int q2 = query(2*node+1,mid+1,end,l,r);
    return q1+q2;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    build(1,0,n-1);
    while (1)
    {
        int type;
        cin>>type;
        if(type == -1){
            break;
        }
        if(type == 1){
            int l,r;
            cin>>l>>r;

            int ans=query(1,0,n-1,l,r);
            cout<<ans<<endl;
        }
    }
    
 return 0;
}