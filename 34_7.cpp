// Cycle detection in undirected graph
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
 
using namespace std;
 
bool iscycle(int src,vector<vector<int>> &adj,vector<bool> &visited,int parent){
    visited[src]=true;
    for(auto i: adj[src]){
        if(i != parent){
            if(visited[i]){
                return true;
            }
            if(!visited[i] and iscycle(i,adj,visited,src)){
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n,m;cin>>n>>m;
    // n=no. of vertices,m=no. of edges 
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool cycle = false;
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i] and iscycle(i,adj,visited,-1)){
            cycle=true;
        }
    }
    if(cycle){
        cout<<"cycle is present"<<endl;
    }else{
        cout<<"cycle is absent"<<endl;
    }
 return 0;
}