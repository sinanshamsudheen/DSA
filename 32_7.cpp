#include<iostream>
#include<set>
#include<vector>
#include<climits>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
 
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first 
#define ss second
#define setBits(x) builtin_popcount(x)
using namespace std;
 
int main()
{
    int n,k;
    cin>>n>>k;

    vi a(n);

    rep(i,0,n){
        cin>>a[i];
    }
    map<int,int> freq;

    rep(i,0,n){
        int presentSize= freq.size();
        if(freq[a[i]] == 0 && presentSize==k){
            break;
        }
        freq[a[i]]++;
    }

    vector<pair<int,int>> ans;
    map<int,int> :: iterator it;
    for(it=freq.begin();it!=freq.end();it++){
        if(it->ss != 0){

            pii p;
            p.ff=it->ff;
            p.ss=it->ss;
            ans.push_back(p);
        }
    }
    sort(ans.begin(),ans.end(),greater<pii>());

    vii :: iterator it1;
    for(it1 = ans.begin();it1!=ans.end();it1++){
        cout<<it1->ss <<" "<<it1->ff<<endl;
    }
 return 0;
}