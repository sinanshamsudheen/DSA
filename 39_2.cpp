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

int main()
{
    string s = "na";
    string t = "apna collegena";
    int S = s.size(), T = t.size();
    for(int i=0;i<T - S + 1; i++){
        if(t.substr(i,S) == s){
            cout<<"Found at index "<<i<<endl;
        }
    }
    //TC : O(S*T)
 return 0;
}