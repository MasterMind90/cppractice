#include <bits/stdc++.h>
using namespace std;

int main(){
    string s ;
    cin >> s ;
    string a[5];
    for(int i=0;i<5;i++){
        cin >> a[i];
    }
    for(int i=0;i<5;i++){
        if ( s[0] == a[i][0] ){
            cout << "YES" << endl;
            return 0 ;
        }
    }
    for(int i=0;i<5;i++){
        if ( s[1] == a[i][1] ){
            cout << "YES" << endl;
            return 0 ;
        }
    }
    cout << "NO" << endl;
    return 0 ;
}
