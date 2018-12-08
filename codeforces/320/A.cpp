#include <bits/stdc++.h>
using namespace std;

int main(){
    string s ;
    cin >> s ;
    while(s.size()>0){
        if ( s[0] == '1' ){
            if ( s.size() == 1 ) break;
            if ( s[1] == '4' && s[2] == '4' ){
                s.erase(0,3);
            }
            else if ( s[1] == '4' ){
                s.erase(0,2);
            }
            else if ( s[1] == '1' ) {
                s.erase(0,1);
                continue;
            }
            else {
                cout << "NO" << endl;
                return 0 ;
            }
        }
        else {
            cout << "NO" << endl;
            return 0 ;
        }
    }
    cout << "YES" << endl;
    return 0 ;
}
