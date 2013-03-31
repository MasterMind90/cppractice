#include <iostream>
using namespace std;
string str;
int counter1,counter2;
int main(){
    cin >> str ;
    for(int i=0;i<str.length();i++){
        if (str[i]=='1'){
            counter1++;
            counter2=0;
        }
        else if (str[i]=='0'){
            counter2++;
            counter1=0;
        }
        if (counter1>=7 || counter2>=7){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
