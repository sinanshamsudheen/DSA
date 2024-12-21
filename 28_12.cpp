//SET
#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;
int main()
{   
    cout<<"SET"<<endl;
    //Insertion,Erase and print
    cout<<"Insertion,Erase and print outputs :- "<<endl;
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);

    for(auto i:s){
        cout<<i<<" ";
    }
        cout<<endl;
        cout<<s.size()<<endl;
        s.erase(2);
    for(auto i:s){
        cout<<i<<" ";
    }cout<<endl;

    //Print in Reverse
    cout<<"Print in reverse output :- "<<endl;
    for(auto i=s.rbegin();i != s.rend();i++){
        cout<<*i<<" ";
    }cout<<endl;
    
    //Size of the set
    cout<<s.size();
    cout<<endl;
    //Custom Comparator
    cout<<"Custom comparator output :- "<<endl;
    set<int, greater<int>> k;
    k.insert(6);
    k.insert(7);
    k.insert(8);
    //Printing the element in the set
    for(auto i:k){
        cout<<i<<" ";
    }cout<<endl;

    //Lower/Upper_bound()
    cout<<"lower/Upper bound output :-"<<endl;
    set<int> r;
    r.insert(11);
    r.insert(12);
    r.insert(13);

    cout<<*r.lower_bound(2)<<endl;
    cout<<*r.lower_bound(12)<<endl;
    cout<<*r.upper_bound(12)<<endl;
    cout<<(r.upper_bound(13)==r.end())<<endl;

    //MULTISET
    cout<<"MULTISET"<<endl;
    multiset<int> m;
    m.insert(1);
    m.insert(3);
    m.insert(3);
    m.insert(3);
    m.insert(5);
    for(auto i:m){
        cout<<i<<" ";
    }cout<<endl;

    m.erase(3);
    for(auto i:m){
        cout<<i<<" ";
    }cout<<endl;

    //here also we can use the same functions we used in set.


    //UNORDERED SET
    cout<<"Unordered set"<<endl;
    unordered_set<int> u;
    u.insert(1);
    u.insert(3);
    u.insert(2);
    u.insert(5);
      for(auto i:u){
        cout<<i<<" ";
    }cout<<endl;

    u.erase(3);
    for(auto i:u){
        cout<<i<<" ";
    }cout<<endl;

    //here also we can use the same functions we used in set
    // and ordered set(except lower/upper bound).


 return 0;
}