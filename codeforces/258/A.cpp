#include <bits/stdc++.h>
using namespace std;

int main(){

    string s ;
    cin >> s ;
    bool first = true ;
    string ans = "" ;
    for(int i=0;i<s.size();i++){
        if ( s[i] == '0' && first ){
            first = false ;
            continue;
        }
        ans += s.substr(i,1);
    }
    if ( first ) {
        cout << ans.substr(0,ans.size()-1) << endl;
    }
    else cout << ans << endl;

    return 0 ;
}
