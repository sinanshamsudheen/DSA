#include<bits/stdc++.h>

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first 
#define ss second
#define setBits(x) builtin_popcount(x)
using namespace std;
const int N=1e3+2,MOD=1e9+7;

int rootN;

struct Q{
    int idx,l,r;
};
Q q[N];

bool compare(Q q1,Q q2){
    if(q1.l/rootN == q2.l/rootN){
        return q1.r > q2.r;
    }
    return q1.l/rootN < q2.l/rootN;
}
signed main()
{
    int n;cin>>n;

    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    rootN = sqrtl(n);
    int queries;
    cin>>queries;

    for(int i=0;i<queries;i++){
        int l,r;
        cin>>l>>r;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;
    }
    sort(q,q+queries,compare);
    vi ans(queries);
    int curr_l =0, curr_r = -1, l, r;
    int curr_ans=0;
    for(int i=0; i< queries;i++){
        l = q[i].l; r=q[i].r;
        l--; r--;

        while(curr_r < r){
            curr_r++;
            curr_ans += a[curr_r];
        }
        while (curr_l > l)
        {
            curr_l--;
            curr_ans += a[curr_l];
        }
        while(curr_l < l){
            curr_ans -= a[curr_l];
            curr_l++;
        }
        while(curr_r > r){
            curr_ans -= a[curr_r];
            curr_r--;
        }
         ans[q[i].idx] = curr_ans;
    }
    for(int i=0;i<queries;i++){
        cout<<ans[i]<<endl;
    }
 return 0;
}