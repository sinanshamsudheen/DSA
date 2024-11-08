// matrix multiplication

// #include<iostream>
// using namespace std;
// int main()
// {
//     int p,q,r,s;
//     cout<<"enter col & row for matrix 1";
//     cin>>p>>q;
//     int a1[p][q];
//     cout<<" enter the values of matrix 1"<<endl;
//     for(int i=0;i<p;i++){
//         for(int j=0;j<q;j++){
//             cin>>a1[p][q];
//         }
//     }

//     cout<<"enter col & row for matrix 2 ";
//     cin>>r>>s;

//     cout<<" enter the values of matrix 2 "<<endl;
//     int a2[r][s];
//     for(int i=0;i<r;i++){
//         for(int j=0;j<s;j++){
//             cin>>a2[r][s];
//         }
//     }

//     for(int i=0;i<p;i++){
//         for(int j=0;j<s;j++){
//             cout<<a1[p][q]*a2[r][s]<<" ";
//         }cout<<endl;
//     }
//  return 0;
// } 

#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n1,n2,n3;
    cin>>n1>>n2>>n3;

    int m1[n1][n2];
    int m2[n2][n3];

    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            cin>>m1[i][j];
        }
    }
    for(int i=0;i<n2;i++){
        for(int j=0;j<n3;j++){
            cin>>m2[i][j];
        }
    }
    int ans[n1][n3];
    for(int i=0;i<n1;i++){
        for(int j=0;j<n3;j++){
            ans[i][j]=0;
        }
    }
    for(int i=0;i<n1;i++){
        for(int j=0;j<n3;j++){
            for(int k=0;k<n2;k++){
                ans[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }
    for(int i=0;i<n1;i++){
        for(int j=0;j<n3;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
 return 0;
}