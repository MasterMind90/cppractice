#include <bits/stdc++.h>
using namespace std;

int main(){
    int t ;
    cin >> t ;
    while(t--){
        int n ;
        cin >> n ;
        string s ;
        cin >> s ;
        int index = -1 ;
        for(int i=0;i<s.size();i++){
            if ( s[i] == '8' ){
                index = i ;
                break;
            }
        }
        if ( index == -1 ){
            cout << "NO" << endl;
        }
        else{
            if ( n - index >= 11 ){
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
    }
    return 0 ;
}
