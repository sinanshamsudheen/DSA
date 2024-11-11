#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string str;
    string str1(5, 'n');

    getline(cin, str);
    cout<<str;
    cout<<str1<<endl;

    // append or mix

    string s1="fam";
    string s2="ily";
    s1.append(s2);
    // or use s1=s1+s2;
    cout<<s1<<endl;
    cout<<s1[3]<<endl;
    
// to clear a string
 string abc="i love indians";
 abc.clear();

// to compare strings
string s3="abc";
string s4="xyz";
if(s3.compare(s4)==0){
    cout<<"strings are equal"<<endl;
}else{
    cout<<"strings are not equal"<<endl;
}

// empty function

string s5="jkl";
cout<<s5<<endl;
s5.clear();

if(s5.empty()){
    cout<<"string is empty"<<endl;
}

// erase function

string s6= "nincompoop";

s6.erase(3, 3);
cout<<s6<<endl;

cout<<s6.find("poo")<<endl;

// insert function

s6.insert(2, "bitch");
cout<<s6<<endl;

// length or size function
cout<<s6.size()<<endl;
for(int i=0;i<s6.length();i++){
    cout<<s6[i]<<endl;
}

// substring function

cout<<s6.substr(6, 4)<<endl;

// string to integer
string s7= "996";
int x = stoi(s7);
cout<<x+3<<endl;

// integer to string
int k= 567;
cout<<to_string(k)+ "2"<<endl;

// sorting function

string s8= "ajflzdfafxxfsafawrwae";
sort(s8.begin(),s8.end());
cout<<s8<<endl;
 return 0;
}