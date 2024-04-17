#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int amount;

    int note100, note50, note20, note1;
    note100=note50=note20=note1=0;

    cout<<"Enter the amount: ";
    cin>>amount;
    if(amount>=100){
        note100=amount/100;
        amount-=amount*100;
    }
    if(amount>=50){
        note50=amount/50;
        amount-=amount*50;
    }
    if(amount>=20){
        note20=amount/20;
        amount-=amount*20;
    }
    if(amount>=1){
        note1=amount/1;
        amount-=amount*1;
    }

    cout << "Total number of notes: " << endl;
    cout << "100 = " << note100 << endl;
    cout << "50 = " << note50 << endl;
    cout << "20 = " << note20 << endl;
    cout << "1 = " << note1 << endl;
    return 0;

}