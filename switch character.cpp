#include<iostream>
using namespace std;

int main(){
    char ch='1';

    cout<<endl;
    switch(ch){

        case 1: cout<<"First"<<endl;
                break;
        case '1': cout<<"character one"<<endl;
                break;
        default: cout<<"It is a default case"<<endl;
    }
    cout<<endl;
}