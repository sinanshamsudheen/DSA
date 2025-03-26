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

int tree[4*N],a[N];

void build(int node,int st,int en){
    if(st==en){
        tree[node]=a[st];
        return;
    }
    int mid=(st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);
    tree[node] = max(tree[2*node],tree[2*node+1]);
}
int query(int node,int st,int end,int l,int r){
    if(st > r || end < l){
        return INT_MIN;
    }
    if(l<= st && end<= r){
        return tree[node];
    }
    int mid=(st+end)/2;

    int q1 = query(2*node,st,mid,l,r);
    int q2 = query(2*node+1,mid+1,end,l,r);
    return max(q1,q2);
}
void update(int node,int st,int en,int idx,int val){
    if(st==en){
        a[st]=val;
        tree[node]=val;
        return;
    }
    int mid=(st+en)/2;
    if(idx<=mid){
        update(2*node,st,mid,idx,val);
    }
    else{
        update(2*node+1,mid+1,en,idx,val);
    }
    tree[node]=max(tree[2*node],tree[2*node+1]);
}
int main()
{
    int n;cin>>n;

    rep(i,0,n){
        cin>>a[i];
    }

    build(1,0,n-1);
    while(1){
        int type;cin>>type;
        if(type==-1){
            break;
        }
        if(type==1){
            int l,r;
            cin>>l>>r;
            int ans = query(1,0,n-1,l,r);
            cout<<ans<<endl;
        }
        else if(type==2){
            int idx,val;
            cin>>idx>>val;
            update(1,0,n-1,idx,val);
            cout<<query(1,0,n-1,0,n-1)<<endl;
        }
    }
 return 0;
}
