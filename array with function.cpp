#include<iostream>
using namespace std;

void printArray(int arr[], int size){
    for(int i=0;i<=size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int number[15];
    cout<<"Value at Zero index "<<number[1]<<endl;

    int second[3]={5,7,11};
    cout<<"Value at Zero index "<<second[0]<<endl;

    int third[15]={2,7};
    int n=15;
    printArray(third,15);
    // cout<<"prinithing the array"<<endl;
    // for(int i=0;i<=n;i++){
    //     cout<<third[i]<<" ";
    // }

    int fourth[10]={0};
    int m=10;
    cout<<"printing the array"<<endl;

    int fifth[10]={1};

    n=10;
    printArray(fifth,10);

    int fifthSize=sizeof(fifth)/sizeof(int);
    cout<<"size of fifith"<<fifthSize<<endl;
    
    
    return 0;
}