//Dutch National Flag Sort also known as 0,1,2 sort
#include<iostream>

using namespace std;

void swap(int arr[],int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp; 
}
void DnfSort(int arr[],int n){
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid <= high){
        if(arr[mid]==0){
            swap(arr,low,mid);
            low++;mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr,mid,high);
            high--;
        }
    }
}


int main(){

    int n = 9;
    int arr[n]={1,0,2,1,0,1,2,1,2};
    DnfSort(arr,n);

    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

//Time Complexity is O(n)