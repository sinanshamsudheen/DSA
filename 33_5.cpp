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

// #define int long long
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
    int n;
    cin>>n;

    vector<int> a(n);

    rep(i,0,n){
        cin>>a[i];
    }

    priority_queue<int,vector<int>,greater<int> > minheap;
    for(int i=0;i<n;i++){
        minheap.push(a[i]);
    }
    int ans=0;

    while(minheap.size() > 1){
        int e1=minheap.top();
        minheap.pop();
        int e2 = minheap.top();
        minheap.pop();

        ans += e1 + e2;
        minheap.push(e1 + e2);
    }
    cout<<ans<<endl;

 return 0;
}