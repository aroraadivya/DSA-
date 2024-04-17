#include<iostream>
using namespace std;

int main(){
    int num;
    cin>>num;
    cout<<endl;

    switch(num){
        case 1: cout<<"First"<<endl;
                break;
        case 2: cout<<"Second"<<endl;
                break;
        default: cout<<"it is a default case"<<endl;
    }

    cout<<endl;
    return 0;
}