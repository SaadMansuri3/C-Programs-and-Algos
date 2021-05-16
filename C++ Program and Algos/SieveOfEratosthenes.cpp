#include <iostream>

using namespace std;

void SieveSpf(int n){
    //Smallest Prime Factorization method of Sieve
    int spf[100]={0};

    for(int i=2;i<=n;i++){
        spf[i] = i;
    } 
    for(int i=2;i<=n;i++){
        if(spf[i]== i){
            for(int j = i*i;j<=n;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }

    while(n!=1){
        cout<<spf[n]<<" ";
        n = n/spf[n];
    }
}

void PrimeSieve(int n){
    //Simple way to go with Sieve Eratosthenes
    int primeArr[100] = {0};

    for(int i=2; i<=n;i++){
        if(primeArr[i]==0){
            for(int j = i*i;j<=n;j+=i){
                primeArr[j] = 1;

            }
        }
    }
    for(int i=2;i<=n;i++){
        if(primeArr[i]==0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
int main(){
    int n;
    n = 30;

    //SieveSpf(n);
    //PrimeSieve(n);

    return 0;
}