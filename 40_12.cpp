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

struct triplet{
    int l,r,idx;
};

int tree[4*N],a[N];

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
    tree[node]=(tree[2*node] + tree[2*node+1]);
}

bool compare(triplet t1,triplet t2){
    return t1.r < t2.r;
}
int main()
{
    int n;cin>>n;
    triplet t1;
    t1.l = t1.r = -1;
    vector<triplet> t(n,t1);

    int x;

    for(int i=0;i<2*n;i++){
        cin>>x;

        if(t[x].l==-1){
            t[x-1].l=i;
        }
        else{
            t[x-1].r=i;
        }
        t[x-1].idx=x;
    }
    sort(t.begin(),t.end(),compare);

    vi ans(n);
    for(int i=0;i<n;i++){
        ans[t[i].idx-1] = query(1,0,2*n-1,t[i].l,t[i].r);
        update(1,0,2*n-1,t[i].l,1);
    }

    rep(i,0,n){
        cout<<ans[i]<<" ";
    }
 return 0;
}