#include <iostream>

using namespace std;

int BinSearch(int target,int arr[],int L, int R){
    
    while(L<=R){
        int mid = L + (R-L)/2;
        if(arr[mid]==target){
            return mid+1;
        }
        if(arr[mid]<target){
            L = mid+1;
        }
        else{
            R = mid-1;
        }
    }
    return -1;
}

int main(){
    int n = 10;
    int arr[10] = {2,26,35,39,55,64,98,110,223,4556};
    int target = 4556;

    cout<<BinSearch(target, arr, 0, n)<<endl;

    return 0;
}