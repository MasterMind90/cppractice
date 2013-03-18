#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
string str1,str2;
int main(){
    cin >> str1 ;
    cin >> str2 ;
    for(int i=0;i<str1.length();i++){
        if (str1[i]==str2[i]) cout << 0;
        else cout << 1;
    }
    cout << endl;
    return 0;
}
