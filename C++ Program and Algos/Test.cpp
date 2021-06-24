#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T=0,A=0,D=0;
    string strr;
    cin>>T>>strr;
    int halflen = T/2;

    for(int i=0;i<strr.size();i++){
        if(strr[i]=='A'){
            A++;
            if(A>halflen){
                cout<<"Anton";
                break;
            }
        }
        else{
            D++;
            if(D>halflen){
                cout<<"Danik";
                break;
            }
        }
    }
    if(A==D){
        cout<<"Friendship";
    }

    return 0;
}