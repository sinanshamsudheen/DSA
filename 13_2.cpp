#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string str="ajflaehoraczkhdvh";

    // convert into upper case
    for(int i=0;i<str.size();i++){
        if(str[i]>='a' and str[i]<='z'){
            str[i] -= 32;
        }
    }cout<<str<<endl;
    // convert into lower case
    for(int i=0;i<str.size();i++){
        if(str[i]>='A' and str[i]<='Z'){
            str[i] += 32;
        }
    }cout<<str<<endl;

    // transform function
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout<<str<<endl;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout<<str<<endl;

    // form the biggest number string
    string s="2394234072345";
    sort(s.begin(), s.end(), greater<int>());
    cout<<s<<endl;

    // frequency and size

    string s1= "ajldqerhoqahaffffd";
    int freq[26];
    for(int i=0;i<26;i++){
        freq[i]=0;
    }
        for(int i=0;i<s1.size();i++){
            freq[s1[i]-'a']++;
        }
    
    char ans ='a';
    int maxF=0;

    for(int i=0;i<26;i++){
        if(freq[i]>maxF){
           maxF=freq[i];
            ans=i+'a';
        }
    }
    cout<<maxF<<" "<<ans<<endl;

 return 0;
}

// transform fn,
// 1st and 2nd = pass the whole string(we gives begin and end).
// 3rd one = u wanna transform from which element?
// 4th one = toupper or tolower.

