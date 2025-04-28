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

int main()
{
    int n;cin>>n;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    int len = (int)sqrtl(n) + 1;
    vi b(len,MOD);

    for(int i=0;i<n;i++){
        b[i/len] = min(b[i/len],a[i]);
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int ans=MOD;
        for(int i=l;i<=r;){
            if(i%len == 0 && i+len-1 <= r){
                ans = min(ans,b[i/len]);
                i += len;
            }
            else{
                ans= min(ans,a[i]);
                i++;
            }
        }
        cout<<ans<<endl;
    }
 return 0;
}