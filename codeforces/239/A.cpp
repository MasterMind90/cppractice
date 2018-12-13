#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main(){
    ll y , k , n ;
    cin >> y >> k >> n ;
    bool f = false ;
    for(ll i=1LL;;i++){
        ll res = i*k ;
        if ( res > n ) break;
        if ( res > y && res <= n ){
            cout << res - y << " " ;
            f = true ;
        }
    }
    if ( !f ) {
        cout << -1 << endl;
    }
    else cout << endl;
    return 0 ;
}
