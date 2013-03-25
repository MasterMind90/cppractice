#include <iostream>
using namespace std;
int main(){
    string str="";
    cin >> str ;
    int small=0;
    int cap=0;
    for(int i=0;i<str.length();i++){
        if ( str[i]>='a' && str[i]<='z')small++;
        if(str[i]>='A' && str[i]<='Z')cap++;
    }
    if (str[0]>='a' && str[0]<='z' && small==1){
        cout << char(str[0]-32);
        for(int i=1;i<str.length();i++){
            cout << char(str[i]+32);
        }
        cout << endl;
        return 0;
    }
    if (small==0){
        for(int i=0;i<str.length();i++){
            cout << char(str[i]+32);
        }
        cout << endl;
    }
    else cout << str << endl;
    return 0;
}
