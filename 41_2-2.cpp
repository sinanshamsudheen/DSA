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

int query(int i,int bit[],int n){
    int ans=0;
    while(i > 0){
        ans += bit[i];
        i -= i &(-i); //to remove LSB 
    }
    return ans;
}
void update(int i,int inc,int bit[],int n){
    while(i <= n){
        bit[i] += inc;
        i += i &(-i);
    }
}


int main()
{
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int bit[n+10] = {0};
        int u;cin>>u;
        while(u--){
            int l,r,inc;
            cin>>l>>r>>inc;
            l++;r++;
            update(l,inc,bit,n);
            update(r+1,-inc,bit,n);
        }
        int q;cin>>q;
        while(q--){
            int w;cin>>w;
            w++;
            cout<<query(w,bit,n)<<endl;
        }
    }

 return 0;
}