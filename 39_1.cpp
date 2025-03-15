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
int p=31;
vector<long long> powers(N);

long long calculate_hash(string s){
    long long hash = 0;
    for(int i=0;i<s.size(); i++){
        hash = (hash + (s[i] - 'a' + 1)*powers[i])%MOD;
    }
    return hash;
}
int main()
{
    powers[0]=1;
    for(int i=0;i<N;i++){
        powers[i]=(powers[i-1] * p)%MOD;
    }
    vector<string> strings={"aa","ab","aa","b","cc","aa"};

    // Normal method
    // sort(strings.begin(),strings.end());
    // //TC : O(nmlong(n))
    // int distinct = 0;
    // for(int i=0;i<strings.size(); i++){
    //     if(i==0 or strings[i] != strings[i-1]){
    //         distinct++;
    //     }
    // }
        // cout<< distinct;
    //string hashing
    vector<long long> hashes;
    for(auto w : strings){
        hashes.push_back(calculate_hash(w));
    }
    sort(hashes.begin(), hashes.end());
    int distinct = 0;
    for(int i=0; i<hashes.size(); i++){
        if(i==0 or hashes[i] != hashes[i-1]){
            distinct++;
        }
    }
        cout<<distinct<<endl;
 return 0;
}