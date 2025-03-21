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
int p = 31;
vector<long long> powers(N);
int main()
{
    string s = "na";
    string t = "apnaacollegena";
    int T = t.size(), S = s.size();

    powers[0]=1;
    for(int i=1; i<N;i++){
        powers[i]=(powers[i-1]*p)%MOD;
    }

    vector<long long> h(T+1,0);
    for(int i = 0;i<T; i++){
        h[i+1] = (h[i] + (t[i] - 'a' + 1)*powers[i])%MOD;
    }

    long long h_s = 0;
    for(int i=0;i<S;i++){
        h_s = (h_s + (s[i] - 'a' + 1)*powers[i])%MOD;
    }
    for(int i=0;i+S - 1<T ;i++){
        long long cur_h = (h[i+S] - h[i] + MOD)%MOD;
        if(cur_h ==(h_s * powers[i]) %MOD){
            cout<<"Found at index "<<i<<endl;
        } 
    }
 return 0;
}