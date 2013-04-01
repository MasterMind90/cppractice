#include <iostream>
using namespace std;
string str ;
int counter;
int main(){
    cin >> str ;
    for(int i=0;i<str.length();i++)
        if (str[i]=='7'||str[i]=='4')counter++;

    while(counter >= 10 ){
        int rem = counter %10;
        if (rem != 4 && rem != 7){
            cout << "NO" << endl;
            return 0;
        }
        counter /=10;
    }
    if (counter == 4 || counter == 7 )
        cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
