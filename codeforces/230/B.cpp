#include <bits/stdc++.h>
using namespace std;
using ll = long long ;

bool check(ll x){
    if ( x == 1 || x == 0 ){
        return false ;
    }
    for(ll i = 2; i * i <= x; i++){
        if ( x % i == 0 ) return false ;
    }
    return true ;
}

const double EPS = 1e-6;

int main(){
    ll n ;
    scanf("%I64d", &n);
    for(int i = 0; i < n; i++){
        ll x ;
        scanf("%I64d", &x);
        double res = sqrt(x) ;
        if ( res - (int) res < EPS ){
            if ( check((int) res) ){
                puts("YES");
            }
            else puts("NO");
        }
        else puts("NO");
    }
    return 0 ;
}
