#include <bits/stdc++.h>
using namespace std;
typedef long long ll ; 
int main(){
    ll n ;
    cin >> n ;
    vector<ll> v(n) ; 
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    ll d = v[0];
    ll e = 0 ; 
    for(int i=1;i<n;i++){
        ll diff = v[i-1] - v[i];
        if ( diff >= 0 ) e += diff ; 
        else {
            if ( abs(diff) <= e ){
                e -= abs(diff) ; 
            }
            else{
                d += abs(diff)-e;
                e = 0 ;
            }
        }
    }
    cout << d << endl;
    return 0 ; 
}
