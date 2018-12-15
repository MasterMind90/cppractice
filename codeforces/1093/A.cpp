#include <bits/stdc++.h>
using namespace std;

int main(){
    int t ;
    cin >> t ;
    while(t--){
        int x ;
        cin >> x ;
        if ( x >= 2 && x <= 7 ){
            cout << 1 << endl;
            continue ;
        }
        int ans = x / 7 ;
        if ( x % 7 != 0 ) ans++;
        cout << ans << endl;
    }

    return 0 ;
}
