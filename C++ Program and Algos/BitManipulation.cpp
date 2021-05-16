#include<iostream>
#include<string>

using namespace std;

int GetBit(int n, int pos){
    //Get the bit position at pos
    return ((n & (1<<pos))!=0);
}

int SetBit(int n, int pos){
    return(n|(1<<pos));
}

int ClearBit(int n, int pos){
    int mask = ~(1<<pos);
    return(n&mask);
}

int UpdateBit(int n, int pos,int value){
     int mask = ~(1<<pos);
     n = n&mask;
     return (n|(value<<pos));

}
bool IsPowerOfTwo(int n){
    return (n&&!(n&n-1));
}

int IsOnes(int n){
    int counter = 0;
    while(n){
        counter++;
        n = (n&n-1);
    }
    return counter;
}

void PossibleSubsets(int arr[],int n){
     for(int i=0;i<(1<<n);i++){
         for(int j=0;j<n;j++){
            if(i&(1<<j)){
                cout<<arr[j]<<" ";
            }
         }
         cout<<endl;
     }
}

int uniqueOne(int arr[], int n){
    int result =0;
    for(int i=0; i<64; i ++){
        int sum = 0;
        for(int j=0; j<n;j++){
            if(GetBit(arr[j],i)){
                sum++;
            }
        }
        if(sum%3!=0){
            result = SetBit(result,i);  

        }
    }
    return result;
}

int main(){
    //cout<<GetBit(5,1);
    //cout<<SetBit(5,1);
    //cout<<ClearBit(5,2);
    //cout<<UpdateBit(5,1,1);
    //cout<<IsPowerOfTwo(8);
    //cout<<IsOnes(19);
    int arr[10] = {1,2,3,4,1,2,3,1,2,3};
    cout<<uniqueOne(arr,10);
}