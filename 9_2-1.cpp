// to find the transpose of the matrix

// #include<iostream>
// using namespace std;
// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     int a[n][m];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>a[i][j];
//         }
//     }
//     cout<<"the transpose of this matrix is:- "<<endl;

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cout<<a[j][i]<<" ";
//         }
//     }

//  return 0;
// }

#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int temp = a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;

        }
    }
    cout<<"the transpose of this matrix is:- "<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }

 return 0;
}