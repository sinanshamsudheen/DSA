// #include<iostream>
// #include<set>
// #include<vector>
// #include<climits>
// #include<map>
// #include<unordered_map>
// #include<queue>
// #include<stack>
// #include<algorithm>
// #include<cstring>

// #define vi vector<int>
// #define pii pair<int,int>
// #define vii vector<pii>
// #define rep(i,a,b) for(int i=a;i<b;i++)
// #define ff first 
// #define ss second
// #define setBits(x) builtin_popcount(x)
// using namespace std;
// const int N=1e3+2,MOD=1e9+7;

// class node{
//     node* next[26];
//     bool end;
//     node(){
//         for(int i=0; i<26; i++){
//             next[i]=NULL;
//         }
//         end = false;
//     }

// class Trie{
//     private:
//     node* root;
//     public:
//     Trie(){
//         root = new node();
//     }
//     void insert(string &s){
//         node* it = root;
//         for(auto c :s){
//             if(!it->next[c-'a']){
//                 it->next[c-'a'] = new node();          
//             }
//             it = it->next[c-'a'];
//         }
//         it->end = true;
//     }
//     void find(string &s){
//         node *it = root;
//         for(auto c : s){
//             if(!it->next[c-'a']){
//                 cout<<"No suggestions\n";
//                 insert(s);
//                 return;
//             }
//         }
//     }
// }
// }
// int main()
// {
//  return 0;
// }