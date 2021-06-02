#include <iostream>
using namespace std;

void MergeFunc(int arr[],int mid, int l, int r){

    int n1 = mid-l+1; 
    int n2 = r-mid;

    int a[n1];
    int b[n2];

    for(int i = 0; i<n1;i++){
        a[i] = arr[l+i];
    }
    for(int j = 0; j<n2;j++){
        b[j] = arr[mid+1+j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k] = a[i];
            k++;
            i++;
        }
        else{
            arr[k] = b[j];
            k++;
            j++;
        }
    }

    while(i<n1){
        arr[k] = a[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k] = b[j];
        k++;
        j++;
    }

}


void MergeSortt(int arr[], int l, int r){

    if(l<r){
        int mid = (l+r)/2;

        MergeSortt(arr,l,mid);
        MergeSortt(arr,mid+1,r);

        MergeFunc(arr,mid,l,r);
    }
    
    
}

int main() {
    
    int arr[8] = {6,3,9,5,2,8,7,1};
    
    for(int i=0; i<8;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    MergeSortt(arr,0,8);

    for(int i=0; i<8;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

	return 0;
}
