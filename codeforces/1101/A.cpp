#include <bits/stdc++.h>
using namespace std;

int main(){
    int q ;
    cin >> q ;
    while(q--){
        long long l , r , d ;
        cin >> l >> r >> d ;
        if ( d < l ) {
            cout << d << endl;
        }
        else{
            long long ans = (r / d + 1LL) * d;
            cout << ans << endl;
        }
    }
    return 0 ;
}
