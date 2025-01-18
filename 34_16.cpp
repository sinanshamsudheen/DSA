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
const int INF=1e9;
 
int main()
{
    int n,m;cin>>n>>m;
    vector<vi> edges;
    rep(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    int src;cin>>src;
    vi dist(n,INF);
    dist[src]=0;
    for(int iter=0;iter<n-1;iter++){
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            dist[v] = min(dist[v],w + dist[u]);
        }
    }
        for(auto i :dist){
            cout<<i<<" ";
        }
        cout<<endl;
 return 0;
}