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

int int_size =32;

class node{
    public:
    node* next[2];
    node(){
        rep(i,0,2){
            next[i]=NULL;
        }
    }
};
node* trie;
void insert(int num){
    node* it = trie;
    for(int i=int_size -1;i>=0; i--){
        int cur_bit = (num >> i) & 1;
        if(!it->next[cur_bit]){
            it->next[cur_bit] = new node();
        }
        it= it->next[cur_bit];
    }
}
int query(int num){
    node *it = trie;
    int ans = 0;
    for(int i=int_size-1;i>=0;i--){
        int cur_bit = (num>>i) & 1;
        int opposite = cur_bit xor 1;
        if(it -> next[opposite]){
            it = it-> next[opposite];
            ans |= 1<<i;
        }
        else{
            it = it -> next[opposite xor 1];
        }
    }
    return ans;
}
int main()
{
    int n;cin>>n;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    trie = new node();
    insert(0);
    vi rmax(n+1,0);
    int R =0;
    for(int i=n-1; i>=0;i--){
        R = R xor a[i];
        if(i != n-1){
            rmax[i] = max(rmax[i+1], query(R));
            insert(R);
        }
        else{
            rmax[i] = query(R);
            insert(R);
        }
    }
    free(trie);
    trie = new node();
    insert(0);
    int ans=0;
    int L=0;
    for(int i=0;i<n;i++){
        L = L xor a[i];
        ans = max(ans,rmax[i+1] + query(L));
        insert(L);
    }
    cout<<ans;
 return 0;
}