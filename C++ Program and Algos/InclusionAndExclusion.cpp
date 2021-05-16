#include <iostream>

using namespace std;

int divisible(int n,int a, int b){
    int c1 = n/a;
    int c2 = n/b;

    int c3 = n/(a*b);

    return c1+c2-c3;
}

int EucladienGCD(int a, int b){

    while(b!=0){
        int remainder = a%b;
        a = b;
        b = remainder;
    }
    return a;
}

int main(){

    //int n = 40;
    //int a = 5;
    //int b = 7;

    //cout<<divisible(n,a,b);

    cout<<EucladienGCD(42,24);
    return 0;
}
