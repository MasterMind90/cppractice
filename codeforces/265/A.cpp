#include <bits/stdc++.h>
using namespace std;

int main(){
    string s ;
    cin >> s ;
    string t ;
    cin >> t ;
    int ans = 1 ;
    for(int i=0;i<t.size();i++){
        if ( s[ans-1] == t[i] ) ans++;
    }
    cout << ans << endl;
    return 0 ;
}
