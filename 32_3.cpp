#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;

// #Define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first 
#define ss second
#define setBits(x) builtin_popcount(x)


int main()
{
    int n;
    cin>> n;

    vi a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int,int> freq;
    rep(i,0,n){
        freq[a[i]]++;
    }

    map<int,int> :: iterator it;
    for(it=freq.begin(); it!=freq.end();it++){
        cout<<it->ff <<" "<< it->ss<<endl;
    }
 return 0;
}

// input,
// 6
// 1 2 1 3 2 1
// output,
// 1 3
// 2 2
// 3 1