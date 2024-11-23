#include<iostream>
using namespace std;

class student{
    string name;
    public:
    int age;
    bool gender;

    student(){
        cout<<"Default constructor"<<endl;
    }

    student(string s,int a,int g){
        cout<<"Parametrized constructor"<<endl;
        name=s;
        age =a;
        gender=g;
    }

    student(student &k){
        cout<<"copy contructor"<<endl;
        name = k.name;
        age=k.age;
        gender=k.gender;
    }
    void setName(string s){ //to access name outside the fn
        name=s; 
        
    }

    ~student(){
        cout<<"Destructor called"<<endl;
    }//destructor
    void getName(){
        cout<<name<<endl;
    }

    bool operator == (student &k){
        if(name == k.name && age==k.age && gender==k.gender){
            return true;
        }
        return false;
    }//Overloading the ""=="operator

    void printInfo(){
        cout<<"name = ";
    cout<<name<<endl;
    cout<<"Age = ";
    cout<<age<<endl;
    cout<<"Gender = ";
    cout<<gender<<endl;
    }
};

int main()
{

    // student arr[3];
    // string s;
    
    // for(int i=0;i<3;i++){
    //     cout<<"Enter name = ";
    //     cin>>s;
    //     cout<<"Enter age = ";
    //     cin>>arr[i].age;
    //     cout<<"Enter gender = ";
    //     cin>>arr[i].gender;
    // }
    // for(int i=0;i<3;i++){
    //     arr[i].printInfo();
    // }

    student k("Sinan",20,0);
    // k.printInfo();
    student b;
    student c=k;//copy constructor

    if(c==k){
        cout<<"same"<<endl;
    }
        else
        {cout<<"Not same"<<endl;}
 return 0;
}