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

vi bit;

int getSum(int idx){
    int sum=0;
    while(idx>0){
        sum += bit[idx];
        idx -= idx& (-idx);
    }
    return sum;
}
void update(int n,int idx,int inc){
    while(idx <= n){
        bit[idx] += inc;
        idx += idx & (-idx);
    }
}
int main()
{
    int n;cin>>n;
    vi a(n);
    for(auto &i :a){
        cin>>i;
    }
    vi temp=a;
    sort(temp.begin(),temp.end());
    for(int i =0;i<n;i++){
        a[i] = lower_bound(temp.begin(),temp.end(),a[i])-temp.begin() + 1;
    }
    bit=vi(n+1);
    int inv = 0;
    for(int i = n-1; i>=0; i--){
        inv += getSum(a[i] - 1);
        update(n,a[i],1);
    }
    cout<<inv;
 return 0;
}