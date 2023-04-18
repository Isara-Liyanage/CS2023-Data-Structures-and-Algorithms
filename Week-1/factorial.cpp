#include <iostream>
using namespace std;

int factorial(int a){
    if (a == 0){
        return 1;
    }
    else{
        return a*factorial(a-1);
    }
}


int main(){
    int a ;
     cout << "Enter a number : "<<"\n";
    cin >> a;
    if(a>=0){
        int out = factorial(a);
        cout << out <<"\n";
    }
    else{
        cout << "Enter a valid number"<<"\n";
    }



     return 0;

}