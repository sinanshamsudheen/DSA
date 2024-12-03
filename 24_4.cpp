// STACK USING QUEUE
#include<iostream>
#include"bits/stdc++.h"
using namespace std;

    class Stack{
        int N;
        queue<int> st1;
        queue<int> st2;

        public:
        Stack(){
            N=0;
        }
        void push(int val){
            st2.push(val);
            N++;
            while(!st1.empty()){
                st2.push(st1.front());
                st1.pop();
            }
            queue<int> temp=st1;
            st1=st2;
            st2=temp;
        }
        void pop(){
            st1.pop();
            N--;
        }
        int top(){
            return st1.front();
        }
        int size(){
            return N;
        }

    };
int main()
{   
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<st.top()<<endl;
    st.pop();

    cout<<st.top()<<endl;
    st.pop();

    cout<<st.top()<<endl;
    st.pop();

    cout<<st.top()<<endl;
    st.pop();


    cout<<st.size()<<endl;
 return 0;
}