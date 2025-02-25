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

//ax + by = gcd(a,b)
//ax + 0 = a
// gcd(d,0) = d
//y = 0

struct triplet{
    int x,y,gcd;
};

triplet extendedEuclid(int a,int b){
    if(b==0){
        triplet ans;
        ans.x = 1;
        ans.gcd =a;
        ans.y=0;
        return ans;
    }

    triplet smallAns = extendedEuclid(b,a%b);
    triplet ans;
    ans.x = smallAns.y;
    ans.gcd = smallAns.gcd;
    ans.y = smallAns.x - (a/b) * smallAns.y;
    return ans;
}

int multiplicativeModuloInverse(int a,int m){
    triplet temp=extendedEuclid(a,m);
    return temp.x;
}
int main()
{
    int a,b;cin>>a>>b;
    cout<<multiplicativeModuloInverse(a,b);
 return 0;
}