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
pii tree[4*N];
int a[N];

void build(int node,int st,int en){
    if(st==en){
        tree[node].ff=a[st];
        tree[node].ss=1;
        return;
    }
    int mid=(st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);

    if(tree[2*node].ff < tree[2*node + 1].ff){
        tree[node].ff=tree[2*node].ff;
        tree[node].ss=tree[2*node].ss;
    }
    else if(tree[2*node+1].ff < tree[2*node].ff){
        tree[node].ff = tree[2*node+1].ff;
        tree[node].ss = tree[2*node+1].ss;
    }
    else{
        tree[node].ff = tree[2*node].ff;
        tree[node].ss = tree[2*node].ss + tree[2*node+1].ss;
    }
    }
pii query(int node,int st,int end,int l,int r){
    if(st > r || end < l){
        pii p;
        p.ff=MOD;
        p.ss=-1;
        return p;
    }
    if(l<= st && end<= r){
        return tree[node];
    }
    int mid=(st+end)/2;

    pii q1 = query(2*node,st,mid,l,r);
    pii q2 = query(2*node+1,mid+1,end,l,r);
    pii q;

    if(q1.first < q2.first){
        q=q1;
    }else if (q2.ff < q1.ff)
    {
        q=q2;
    }
    else{
        q.ff = q1.ff;
        q.ss = q1.ss + q2.ss;
    }
    return q;
    
}
void update(int node,int st,int en,int idx,int val){
    if(st==en){
        a[st]=val;
        tree[node].ff=val;
        tree[node].ss=1;
        return;
    }
    int mid=(st+en)/2;
    if(idx<=mid){
        update(2*node,st,mid,idx,val);
    }
    else{
        update(2*node+1,mid+1,en,idx,val);
    }
    
    if(tree[2*node].ff < tree[2*node + 1].ff){
        tree[node].ff=tree[2*node].ff;
        tree[node].ss=tree[2*node].ss;
    }
    else if(tree[2*node+1].ff < tree[2*node].ff){
        tree[node].ff = tree[2*node+1].ff;
        tree[node].ss = tree[2*node+1].ss;
    }
    else{
        tree[node].ff = tree[2*node].ff;
        tree[node].ss = tree[2*node].ss + tree[2*node+1].ss;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    rep(i,0,n){
        cin>>a[i];
    }
    build(1,0,n-1);
    while(m--){
        int type;
        cin>>type;
        if(type==1){
            int idx,val;
            cin>>idx>>val;
            update(1,0,n-1,idx,val);
        }
        else if(type==2){
            int l,r;
            cin>>l>>r;

            pii ans = query(1,0,n-1,l,r-1);
            cout<<ans.ff<<" "<<ans.ss<<endl;
        }
    }
 return 0;
}
//input,
// 5 5
// 3 4 3 5 2
// 2 0 3
// 1 1 2
// 2 0 3
// 1 0 2
// 2 0 5
