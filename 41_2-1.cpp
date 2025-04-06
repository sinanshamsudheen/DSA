#include<bits/stdc++.h>
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first 
#define ss second
#define setBits(x) builtin_popcount(x)
using namespace std;
const int N=1e3+2,MOD=1e9+7;
int n;
vi bit;

void update(int idx,int val){
    while(idx <= n){
        bit[idx] += val;
        idx += idx &(-idx);
    }
}

int query(int idx){
    int ans=0;
    while(idx > 0){
        ans += bit[idx];
        idx -= idx &(-idx); //to remove LSB 
    }
    return ans;
}
int main()
{
    cin>>n;
    bit=vi(n+1);
    vi a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        update(i,a[i]);
    }
    int q;cin>>q;
    while(q--){
        int c;cin>>c;
        if(c==1){
            int l,r;cin>>l>>r;
            int ans = query(r) - query(l-1);
            cout<<ans<<"\n";
        }
        else if(c==2){
            int index,val;
            cin>>index>>val;
            update(index,-a[index]);
            a[index]=val;
            update(index,val);
        }
    }

 return 0;
}