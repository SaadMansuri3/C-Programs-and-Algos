#include<iostream>
using namespace std;
int powerr(long long a,long long b){
    cout<<"IN"<<endl;
    long long res = 1;
    while(b>0){
        if(b%2!=0)
            res *= a;
        a=a* (a % 1000000007);
        b/=2;
    }
    return res;
}
int main(){
    int num;
    scanf("%i",&num);
    printf("%i",powerr(2,num));
    return 0;
} 