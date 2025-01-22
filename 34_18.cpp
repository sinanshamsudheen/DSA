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
    int ladders,snakes;
    cin>>ladders;
    map<int,int> lad;
    map<int,int> snak;
    rep(i,0,ladders){
        int u,v;cin>>u>>v;
        lad[u]=v;
    }
    cin>>snakes;
    rep(i,0,snakes){
        int u,v;cin>>u>>v;
        snak[u]=v;
    }
    int moves=0;
    queue<int> q;
    q.push(1);
    bool found = false;
    vector<int> vis(101,0);
    vis[1]=true;
    while(!q.empty() and !found){
        int sz = q.size();
        while (sz--)
        {
            int t=q.front();
            q.pop();
            for(int die=1;die<=6;die++){
                if(t + die == 100){
                    found = true;
                }
                if(t+die <= 100 and lad[t+die] and !vis[lad[t+die]]){
                    vis[lad[t+die]]=true;
                    if(lad[t+die]==100){
                        found=true;
                    }
                    q.push(lad[t+die]);
                }
                else if(t+die <= 100 and snak[t+die] and !vis[snak[t+die]]){
                    vis[snak[t+die]]=true;
                    if(snak[t+die]==100){
                        found=true;
                    }
                    q.push(snak[t+die]);
                }
                else if(t+die <=100 and !vis[t+die] and !snak[t+die] and !lad[t+die]){
                   vis[t+die] =true;
                   q.push(t+die);
                }
            }
        }
        moves++;
        
    }
    if(found){
        cout<<moves;
    }else{
        cout<<-1;
    }


 return 0;
}