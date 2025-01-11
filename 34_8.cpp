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
 bool iscycle(int src,vector<vector<int>> &adj,vector<bool> &visited,vector<int> &stack){
    stack[src]=true;
    if(!visited[src]){
        visited[src]=true;
        for(auto i :adj[src]){
            if(!visited[i] and iscycle(i,adj,visited,stack)){
                return true;
            }
            if(stack[i]){
                return true;
            }
        }
    }  
    stack[src]=false;
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
    }
    bool cycle = false;
    vector<int> stack(n,0);
    vector<bool> visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i] and iscycle(i,adj,visited,stack)){
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