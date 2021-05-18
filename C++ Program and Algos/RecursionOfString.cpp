#include <iostream>

using namespace std;

void ReverseString(string s){
    if(s.length()==0)
        return;
    
    string ros = s.substr(1);
    ReverseString(ros);
    cout<<s[0];
}

void ReplacePi(string s){
    if(s.length()==0)
        return;

    if(s[0] == 'p' && s[1]=='i'){
        cout<<"3.14";
        ReplacePi(s.substr(2));
    }
    else{
        cout<<s[0];
        ReplacePi(s.substr(1));
    }
}

void TowerOfHanoi(int n, char src, char dest, char helper){

    if(n==0)
        return;
    
    TowerOfHanoi(n-1,src,helper,dest);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    TowerOfHanoi(n-1,helper,dest,src);
}

string RemoveDup(string s){
    if(s.length()==0)
        return "";

    char ch = s[0];
    string ans = RemoveDup(s.substr(1));

    if(ch == ans[0])
        return ans;

    return (ch+ans);
}

string ReplaceAll(string s){
    if(s.length()==0)
        return "";

    char ch = s[0];
    string ans = ReplaceAll(s.substr(1));

    if(ch =='x')
        return ans+ch;
    else   
        return ch+ans;
}

void subseq(string s,string ans){
    if(s.length() == 0){
        cout<<ans<<endl;
        return;
    }
    
    char ch = s[0];
    string ros = s.substr(1);

    subseq(ros,ans);
    subseq(ros,ans+ch);

}
 
int main(){

    //ReverseString("Hello World!");
    //ReplacePi("pixsdffdpiipsfspxxpdffpi");
    //TowerOfHanoi(3,'A','C','B');
    //cout<<RemoveDup("aaabbbeeeccdd");
    //cout<<ReplaceAll("xpffdxxpdpfxpegpxxpxpfx");

    subseq("ABC","");
    return 0;
}