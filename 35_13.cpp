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
const int N=1e3+2,MOD=1e9+7;

int main()
{
    int n;cin>>n;

    string s;cin>>s;

    int e=1,a=0,ab=0,abc=0;

    rep(i,0,n){
        if(s[i]=='a'){
            a += e;
        }
        else if(s[i]=='b'){
            ab += a;
        }
        else if(s[i]=='c'){
            abc += ab;
        }
        else if(s[i]=='?'){
            abc = 3*abc + ab;
            ab = 3*ab + a;
            a=3*a + e;
        }
    }
    cout<<abc<<endl;

 return 0;
}
//OPTIMAL MERGE PATTERN

// e -> denoting count of all possible strings upt ocurrent element.

// a -> denoting count of subsequences ('a') in all the strings upto current element.

// ab -> denoting count of subsequences ('a b') in all the strings upto current element.

// abc -> denoting count of subsequences ('a b c') in all the strings upto current element