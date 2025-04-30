// this code aint working, idk why..
#include<bits/stdc++.h>

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first 
#define ss second
#define setBits(x) builtin_popcount(x)
#define int long long
using namespace std;
const int N=2e5+2,MOD=1e9+7;

struct Q{
    int l,r,idx;
};
int rootN;
Q q[N];

bool compare(Q q1,Q q2){
   if(q1.l/rootN == q2.l/rootN){
    return q1.r > q2.r;
   } 
   return q1.l < q2.l;
}
signed main()
{
    int n;
    cin>>n;

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
        q[i].l =l;
        q[i].r = r;
        q[i].idx = i;
    }
    sort(q,q+queries, compare);

    vi ans(queries);
    int curr_l =0,curr_r=-1,l,r;
    int curr_ans =0;
    vi freq(10*N,0);

    for(int i=0; i<queries;i++){
        l = q[i].l; r = q[i].r;
        l--;r--;

        while(curr_r < r){
            curr_r++;
            freq[a[curr_r]]++;
            if(freq[a[curr_r]] == 1){
                curr_ans++;
            }
        }
        while(curr_l > l){
            curr_l--;
            freq[a[curr_l]]++;
            if(freq[a[curr_l]] == 1){
                curr_ans++;
            }
        }
        while( curr_l < l){
            freq[a[curr_l]]--;
            curr_l++;
            if(freq[a[curr_l]] == 0){
                curr_ans--;
            }
        }
        while(curr_r > r){
            freq[a[curr_r]]--;
            curr_r--;
            if(freq[a[curr_r]] == 0){
                curr_ans--;
            }
        }
        ans[q[i].idx] = curr_ans;
    }
    for(int i=0;i<queries;i++){
            cout<<ans[i]<<endl;
        }
 return 0;
}