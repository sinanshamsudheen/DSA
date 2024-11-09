// Array declaration

// check palindrome

// #include<iostream>
// using namespace std;
// int main()
// {
//     int n; cin>>n;
//     char word[n+1];
//     cin>>word;
//     bool check = 1;
//     for(int i=0;i<n;i++){
//         if(word[i]!=word[n-1-i]){
//             check = 0;
//         break;
//         }
//     }
//         if(check==true){
//             cout<<"Word is a palindrome"<<endl;
//         }
//         else{
//             cout<<"word is not a palindrome"<<endl;
//         }
//  return 0;
// }

// largest word in a sentence

#include<iostream>
using namespace std;
int main()
{
    int n; cin>>n;
    cin.ignore();
    char arr[n+1];

    cin.getline(arr, n);
    cin.ignore();

    int currLen =0, maxLen=0,i=0;
    int st=0,maxst=0;

    while(1){
        if(arr[i]=' ' || arr[i]=='\0'){
            if(currLen>maxLen){
                maxLen=currLen;
                maxst=st;
            }
            currLen =0;
            st=i+1;
        }
        else

        currLen++;


        if(arr[i]=='\0'){
            break;
            i++;
        }
    }
    cout<<maxLen<<endl;
    for(int i=0;i<maxLen;i++){
        cout<<arr[i+maxst];
    }
 return 0;
}