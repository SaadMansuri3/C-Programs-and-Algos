#include <iostream>
#include <algorithm>

using namespace std;

int CountPath(int s, int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count = 0;
    for(int i = 1; i<=6;i++){
        count += CountPath(s+i,e);
    }
    return count;
}

int MazePathCount(int n, int i, int j){
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }

    return MazePathCount(n, i+1, j) + MazePathCount(n,i,j+1);
}

int TilingWays(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    return TilingWays(n-1) + TilingWays(n-2);
}

int FriendPair(int n){
    if(n==0||n==1||n==2)
        return n;
    return FriendPair(n-1)+FriendPair(n-2)*(n-1);
}

int Knapsack(int value[], int wt[], int n, int W){ 
    if(n==0|| W==0)
        return 0;
    
    if(wt[n-1]>W){
        Knapsack(value,wt,n-1,W);
    }
    return max(Knapsack(value, wt,n-1,W-wt[n-1])+value[n-1],Knapsack(value,wt,n-1,W));
     
}
int main(){

    int wt[] = {10,20,30};
    int value[] = {100,50,150};
    int W = 50;

    cout<<Knapsack(value,wt,3,W)<<endl;

    return 0;
}