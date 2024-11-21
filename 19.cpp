#include<iostream>
#include "bits/stdc++.h"
#include<vector>
using namespace std;
int main()
{   //Vector

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }

    for(auto elements:v){
        cout<<elements<<endl;
    }

    v.pop_back();
    vector<int> v2 (3,50);

    swap(v,v2);
    for(auto hehe:v2){
        cout<<hehe<<endl;
    }
    for(auto huhu:v){
        cout<<huhu<<endl;
    }
    sort(v.begin(),v.end());


    //pair

    pair <int,char> p;
    p.first = 3;
    p.second = 'f';

 return 0;
}