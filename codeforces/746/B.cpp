#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    string s ; 
    cin >> s ;
    if ( s.size() % 2 == 1 ){
        string ans = "" ; 
        ans += s.substr(0,1);
        for(int i=1;i<s.size();i++){
            if ( i % 2 == 1 ) {
                ans = s.substr(i,1) + ans;
            }
            else ans = ans + s.substr(i,1) ;
        }
        cout << ans << endl;
    }
    else{
        string ans = "" ; 
        ans += s.substr(0,1);
        for(int i=1;i<s.size();i++){
            if ( i % 2 == 1 ) {
                ans = ans + s.substr(i,1) ;
            }
            else 
                ans = s.substr(i,1) + ans;
        }
        cout << ans << endl;
    }
    return 0 ;
}
