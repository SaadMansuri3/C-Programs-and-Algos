#include <iostream>

using namespace std;

int FibonacciNo(int n){
    //Get the fibonacci number at nth place
    if(n==0||n==1){
        return n;
    }
    return FibonacciNo(n-1)+FibonacciNo(n-2);
}

int FactorialNo(int n){
    //factorial of n
    if(n==0)
        return 1;
    int prevFact = FactorialNo(n-1);
    return n*prevFact;
}

bool IsSorted(int arr[], int n){
    //is arr sorted 

    if(n==1)
        return true;
    
    bool sortedArr = IsSorted(arr+1,n-1);
    return (arr[0]<arr[1] && sortedArr);
}

void DecOrder(int n){
    if(n==0){
        return;
    }
    cout<<n<<endl;
    DecOrder(n-1);
}

void IncOrder(int n){
    if(n==0){
        return;
    }
    IncOrder(n-1);
    cout<<n<<endl;
    
}


int main(){

    int n = 4;
    int arr[10] = {10,1,2,3,4,5,6,7,8,9};

    IncOrder(4);



    return 0;
}