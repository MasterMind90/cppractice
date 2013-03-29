#include <iostream>
using namespace std;
int n;
string str;
int counter;
int main(){
    cin >> n;
    cin >> str;
    for(int i=1;i<str.length();i++){
        if (str[i]==str[i-1])counter++;
    }
    cout << counter << endl;
    return 0;
}
