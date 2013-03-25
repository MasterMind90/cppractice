#include <iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    string str="" ;
    int bits=0;
    while(T--){
        cin >> str ;
        if (str[1]=='+') bits++;
        else bits--;
    }
    cout << bits << endl;
    return 0;
}
