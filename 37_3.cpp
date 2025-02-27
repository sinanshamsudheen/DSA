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
int totient[N];
int main()
{
    rep(i,0,N){
        totient[i] = i;
    }
    for(int i=2;i<N;i++){
        if(totient[i]==i){
            for(int j=2*i; j<N; j+=i){
                totient[j] *= i-1;
                totient[j] /= i;
            }
            totient[i] = i-1;
        }
    }

    for(int i=2;i<11;i++){
        cout<<totient[i]<<" ";
    }
 return 0;
}