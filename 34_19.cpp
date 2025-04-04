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
 
void change(vector<vector<char>> &A,int x,int y){
    A[x][y]='*';
    int dx[]={0,0,-1,1};
    int dy[]={1,-1,0,0};
    rep(i,0,4){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if(cx >= 0 and cx<A.size() and cy>=0 and cy<A[0].size() and A[cx][cy]=='O'){
            change(A,cx,cy);
        }
    }
}
int main()
{
    int n,m;cin>>n>>m;
    vector<vector<char>> A(n,vector<char>(m));
    rep(i,0,n){
        rep(j,0,m){
            cin>>A[i][j];
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            if(i==0 or i==n-1 or j==0 or j==m-1){
                if(A[i][j]=='O'){ 
                change(A,i,j);
                }
            }
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            if(A[i][j]=='O'){
                A[i][j]='X';
            }
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            if(A[i][j]=='*'){
                A[i][j]='O';
            }
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
 return 0;
}