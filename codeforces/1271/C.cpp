#include <bits/stdc++.h>

using namespace std;
using ll = long long ;

int main(){
    ll n , sx , sy ;
    cin >> n >> sx >> sy ;
    vector<ll> x(n), y(n) ;
    for(ll i = 0; i < n; i++){
        cin >> x[i] >> y[i] ;
    }
    ll a[] = {0, 0,  -1,   1};
    ll b[] = {1, -1,  0,   0 };
    ll student = 0 ;
    ll curDist = 1e18 ;
    ll ansx = 0, ansy = 0 ;
    for(ll i = 0; i < 4; i++){
        ll px = sx + a[i] ;
        ll py = sy + b[i] ;
        ll cnt = 0 ;
        for(ll j = 0; j < n; j++){
            ll tos = abs(x[j] - sx) + abs(y[j] - sy) ;
            ll top = abs(x[j] - px) + abs(y[j] - py) ;
            if ( top <= tos ) cnt++ ;
        }
        if ( cnt > student ){
            student = cnt ;
            ansx = px ;
            ansy = py ;
        }
    }
    cout << student << endl;
    cout << ansx << ' ' << ansy << endl;
	return 0 ;
}

