#include<iostream>
using namespace std;

// void printArray(){

// }

int main(){
    int number[15];
    cout<<"Value at Zero index "<<number[1]<<endl;

    int second[3]={5,7,11};
    cout<<"Value at Zero index "<<second[0]<<endl;

    int third[15]={2,7};
    int n=15;
    cout<<"prinithing the array"<<endl;
    for(int i=0;i<=n;i++){
        cout<<third[i]<<" ";
    }

    int fourth[10]={0};
    int m=10;
    cout<<"printing the array"<<endl;
    for(int i=0;i<=m;i++){
        cout<<fourth[i]<<" ";
    }
    return 0;
}