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
const int N = 1e9;
int main()
{
    vector<vi> graph={  {0,5,N,10},
                        {N,0,3,N},
                        {N,N,0,1},
                        {N,N,N,0}
                    };
int n=graph.size();
vector<vi> dist=graph;
rep(k,0,n){
    rep(i,0,n){
        rep(j,0,n){
            if(dist[i][k] + dist[k][j] < dist[i][j]){
                dist[i][j]=dist[i][k] + dist[k][j];
            }
        }
    }
}
rep(i,0,n){
    rep(j,0,n){
        if(dist[i][j] == N){
            cout<<"INF ";
        }else{
            cout<<dist[i][j]<<" ";
        }
    }
    cout<<endl;
}
 return 0;
}