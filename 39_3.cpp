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
#include<cmath>

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first 
#define ss second
#define setBits(x) builtin_popcount(x)
using namespace std;
const int N=1e3+2,MOD=1e9+7;

vi prefix_function(string s){
    int n=s.size();
    vi pi(n,0);
    for(int i = 1;i<n;i++){
        int j = pi[i-1];

        while(j>0 and s[i]!=s[j]){
            j=pi[j-1];
        }

        if(s[i] == s[j]){
            j++;
        }
        pi[i]=j;
    }
    return pi;
    // TC = O(n)
}
int main()
{
    // string s="abcabcd";
    string s="na";

    vi prefix=prefix_function(s);
    for(auto i :prefix){
        cout<<i<<" ";
    }cout<<endl;

    string t = "apnacollege";

    int pos = -1;
    int i(0),j(0);
    while(i<t.size()){
        if(t[i] == s[j]){
            j++;
            i++;
        }
        else{
            if(j!=0){
                j=prefix[j-1];
            }
            else{
                i++;
            }
        }
            if(j==s.size()){
                pos = i - s.size();
                break;
            }
    }
    cout<<pos;
 return 0;
}